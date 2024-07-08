#ifndef _UNION_FIND_HEADER_
#define _UNION_FIND_HEADER_
#define NULL 0

typedef struct {
    /* data */
    int* parents;
    int* rank;
    int  size;
} UnionFindByRank;

int UnionFindByRank_alloc(UnionFindByRank* unionfind, int size);

int UnionFindByRank_free(UnionFindByRank* unionfind);
int UnionFindByRank_find(UnionFindByRank* unionfind, int child);
int UnionFindByRank_merge(UnionFindByRank* unionfind, int x, int y);
int UnionFindByRank_size(UnionFindByRank* unionfind);

#endif