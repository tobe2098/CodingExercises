#include "UnionFind.h"

int UnionFindByRank_alloc(UnionFindByRank *unionfind, int size) {
  int *parents = (int *)malloc(size * sizeof(int));
  int *rank    = (int *)malloc(size * sizeof(int));
  if (!(rank && parents)) {
    free(parents);
    free(rank);
    return -1;
  }
  for (int i = 0; i < size; i++) {
    parents[i] = i;
    rank[i]    = 1;
  }
  unionfind->parents = parents;
  unionfind->rank    = rank;
  unionfind->size    = size;
  return 0;
}

int UnionFindByRank_free(UnionFindByRank *unionfind) {
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

int UnionFindByRank_find(UnionFindByRank *unionfind, int child) {
  if (!unionfind || child >= unionfind->size || child < 0) {
    return -1;
  }
  if (unionfind->parents[child] != child) {
    unionfind->parents[child] = UnionFindByRank_find(unionfind, unionfind->parents[child]);
  }
  return unionfind->parents[child];
}

int UnionFindByRank_merge(UnionFindByRank *unionfind, int x, int y) {
  if (!unionfind || unionfind->size <= x || unionfind->size <= y || x < 0 || y < 0) {
    return -1;
  }
  int parent_x = UnionFindByRank_find(unionfind, x);
  int parent_y = UnionFindByRank_find(unionfind, y);
  int rank_x   = unionfind->rank[parent_x];
  int rank_y   = unionfind->rank[parent_y];
  if (rank_x > rank_y) {
    unionfind->parents[parent_y] = parent_x;
  } else if (rank_y > rank_x) {
    unionfind->parents[parent_x] = parent_y;
  } else {
    unionfind->parents[parent_y] = parent_x;
    unionfind->rank[parent_x]++;
  }
  return 0;
}

int UnionFindByRank_size(UnionFindByRank *unionfind) {
  if (unionfind) {
    return unionfind->size;
  } else {
    return -1;
  }
}
