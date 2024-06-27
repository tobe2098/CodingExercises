#include <stdio.h>
#include <stddef.h>

#define MEMORY_POOL_SIZE 1024
#define MIN_BLOCK_SIZE 16
#define MAX_BLOCK_SIZE 512
#define BLOCK_COUNT (MEMORY_POOL_SIZE / MIN_BLOCK_SIZE)

typedef struct Block {
    struct Block* next;
    size_t size;
    int free;
} Block;

static unsigned char memory_pool[MEMORY_POOL_SIZE];
static Block* free_list[BLOCK_COUNT];

void init_memory_pool() {
    for (int i = 0; i < BLOCK_COUNT; ++i) {
        free_list[i] = NULL;
    }

    Block* initial_block = (Block*)memory_pool;
    initial_block->next = NULL;
    initial_block->size = MEMORY_POOL_SIZE;
    initial_block->free = 1;

    free_list[get_block_index(MEMORY_POOL_SIZE)] = initial_block;
}

int get_block_index(size_t size) {
    int index = 0;
    size_t block_size = MIN_BLOCK_SIZE;
    while (block_size < size && block_size < MAX_BLOCK_SIZE) {
        block_size <<= 1;
        index++;
    }
    return index;
}

void split_block(int index) {
    Block* block = free_list[index];
    if (!block) {
        return;
    }

    size_t block_size = MIN_BLOCK_SIZE << index;
    block->size = block_size >> 1;

    Block* buddy = (Block*)((unsigned char*)block + block->size);
    buddy->size = block->size;
    buddy->free = 1;

    free_list[index] = block->next;
    block->next = buddy;
    buddy->next = NULL;

    int new_index = index - 1;
    free_list[new_index] = block;
}

void* allocate(size_t size) {
    size += sizeof(Block); // Include the size of the metadata
    int index = get_block_index(size);
    if (index >= BLOCK_COUNT) {
        return NULL;
    }

    if (!free_list[index]) {
        int next_index = index + 1;
        while (next_index < BLOCK_COUNT && !free_list[next_index]) {
            next_index++;
        }
        if (next_index >= BLOCK_COUNT) {
            return NULL;
        }

        while (next_index > index) {
            split_block(next_index);
            next_index--;
        }
    }

    Block* block = free_list[index];
    block->free = 0;
    free_list[index] = block->next;
    return (void*)((unsigned char*)block + sizeof(Block));
}

void merge_block(Block* block) {
    size_t block_size = block->size;
    unsigned char* block_address = (unsigned char*)block;
    unsigned char* buddy_address = ((block_address - memory_pool) ^ block_size) + memory_pool;
    Block* buddy = (Block*)buddy_address;

    if (buddy->free && buddy->size == block_size) {
        int index = get_block_index(block_size);
        Block** list = &free_list[index];
        while (*list && *list != buddy) {
            list = &(*list)->next;
        }
        if (*list) {
            *list = buddy->next;
        }

        if (buddy < block) {
            block = buddy;
        }
        block->size <<= 1;
        merge_block(block);
    }
    else {
        int index = get_block_index(block_size);
        block->free = 1;
        block->next = free_list[index];
        free_list[index] = block;
    }
}

void deallocate(void* ptr) {
    if (!ptr) {
        return;
    }

    Block* block = (Block*)((unsigned char*)ptr - sizeof(Block));
    merge_block(block);
}

int main() {
    init_memory_pool();

    // Example usage
    int* a = (int*)allocate(sizeof(int));
    *a = 42;

    int* b = (int*)allocate(sizeof(int) * 100);
    for (int i = 0; i < 100; i++) {
        b[i] = i;
    }

    printf("Allocated int at %p with value %d\n", a, *a);
    printf("Allocated int array at %p\n", b);

    deallocate(a);
    deallocate(b);

    return 0;
}

//You're right. In the provided example, the Block structure does not explicitly show where the data is stored, but the memory for the data is effectively just after the Block metadata in memory. This is a common practice in memory allocators where metadata is stored at the beginning of each allocated block, followed by the actual user data.