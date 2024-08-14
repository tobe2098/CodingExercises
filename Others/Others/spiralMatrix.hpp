#pragma once
#include <vector>

const static std::vector<std::pair<int, int>> spiral{ {0,1},{1,0},{0,-1},{-1,0} };
std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart);