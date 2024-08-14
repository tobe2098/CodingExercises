#pragma once
#include <memory>
typedef struct {
    /* data */
    int* parents;
    int* rank;
    int  size;
} UnionFindByRank;

int UnionFindByRank_alloc(UnionFindByRank* unionfind, int size) {
    int* parents = (int*)malloc(size * sizeof(int));
    int* rank = (int*)malloc(size * sizeof(int));
    if (!(rank && parents)) {
        free(parents);
        free(rank);
        return -1;
    }
    for (int i = 0; i < size; i++) {
        parents[i] = i;
        rank[i] = 1;
    }
    unionfind->parents = parents;
    unionfind->rank = rank;
    unionfind->size = size;
    return 0;
}

int UnionFindByRank_free(UnionFindByRank* unionfind) {
    if (!unionfind) {
        return -1;
    }
    free(unionfind->parents);
    unionfind->parents = NULL;
    free(unionfind->rank);
    unionfind->rank = NULL;
    unionfind->size = 0;
    return 0;
}

int UnionFindByRank_find(UnionFindByRank* unionfind, int child) {
    if (!unionfind || child >= unionfind->size || child < 0) {
        return -1;
    }
    if (unionfind->parents[child] != child) {
        unionfind->parents[child] = UnionFindByRank_find(unionfind, unionfind->parents[child]);
    }
    return unionfind->parents[child];
}

int UnionFindByRank_merge(UnionFindByRank* unionfind, int x, int y) {
    if (!unionfind || unionfind->size <= x || unionfind->size <= y || x < 0 || y < 0) {
        return -1;
    }
    int parent_x = UnionFindByRank_find(unionfind, x);
    int parent_y = UnionFindByRank_find(unionfind, y);
    int rank_x = unionfind->rank[parent_x];
    int rank_y = unionfind->rank[parent_y];
    if (rank_x > rank_y) {
        unionfind->parents[parent_y] = parent_x;
    }
    else if (rank_y > rank_x) {
        unionfind->parents[parent_x] = parent_y;
    }
    else {
        unionfind->parents[parent_y] = parent_x;
        unionfind->rank[parent_x]++;
    }
    return 0;
}

int UnionFindByRank_size(UnionFindByRank* unionfind) {
    if (unionfind) {
        return unionfind->size;
    }
    else {
        return -1;
    }
}
int getUnionIndex(int i, int j, int k, int gridSize) {
    return (i * gridSize + j) * 4 +k;
}
int mergeSlash(int i, int j, UnionFindByRank* u, int gridSize) {
    UnionFindByRank_merge(u, getUnionIndex(i, j, 0, gridSize), getUnionIndex(i, j, 1, gridSize));
    UnionFindByRank_merge(u, getUnionIndex(i, j, 3, gridSize), getUnionIndex(i, j, 2, gridSize));
    return 0;
}
int mergeBackslash(int i, int j, UnionFindByRank* u, int gridSize) {
    UnionFindByRank_merge(u, getUnionIndex(i, j, 0, gridSize), getUnionIndex(i, j, 3, gridSize));
    UnionFindByRank_merge(u, getUnionIndex(i, j, 1, gridSize), getUnionIndex(i, j, 2, gridSize));
    return 0;
}
int mergeEmpty(int i, int j, UnionFindByRank* u, int gridSize) {
    UnionFindByRank_merge(u, getUnionIndex(i, j, 0, gridSize), getUnionIndex(i, j, 3, gridSize));
    UnionFindByRank_merge(u, getUnionIndex(i, j, 1, gridSize), getUnionIndex(i, j, 2, gridSize));
    UnionFindByRank_merge(u, getUnionIndex(i, j, 0, gridSize), getUnionIndex(i, j, 1, gridSize));
    UnionFindByRank_merge(u, getUnionIndex(i, j, 3, gridSize), getUnionIndex(i, j, 2, gridSize));
    return 0;
}
int regionsBySlashes(char** grid, int gridSize) {
    UnionFindByRank uni_on;
    if (UnionFindByRank_alloc(&uni_on, gridSize*gridSize * 4)) return 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            if (grid[i][j] == '/') mergeSlash(i, j, &uni_on, gridSize);
            else if (grid[i][j] == '\\') mergeBackslash(i, j, &uni_on, gridSize);
            else if (grid[i][j] == ' ') mergeEmpty(i, j, &uni_on, gridSize);
            //Then merge previous neighbours
            if (i > 0) {
                UnionFindByRank_merge(&uni_on, getUnionIndex(i, j, 1, gridSize), getUnionIndex(i - 1, j, 3, gridSize));
            }
            if (j > 0) {
                UnionFindByRank_merge(&uni_on, getUnionIndex(i, j, 0, gridSize), getUnionIndex(i, j - 1, 2, gridSize));
            }
        }
    }
    int count = 0;
    int* hashmap = (int*)calloc(uni_on.size, sizeof(int));
    //for (int i = 0; i < 30 * 30*4; i++) hashmap[i] = 0;
    for (int i = 0; i < uni_on.size; i++) {
        int parent = UnionFindByRank_find(&uni_on, i);
        hashmap[parent]++;
        if (hashmap[parent] == 1) count++;
    }
    return count;
}