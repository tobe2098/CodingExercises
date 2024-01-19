#pragma once
#include <vector>
#include <bitset>
#include <array>


size_t getNextRow(size_t row, size_t col);
size_t getNextCol(size_t col);
size_t getGrid(size_t row, size_t col);

bool recursiveBacktracking(std::vector<std::vector<char>>& board, size_t row, size_t col, std::array<std::bitset<9>, 9>& rows, std::array<std::bitset<9>, 9>& cols, std::array<std::bitset<9>, 9>& grids);

void solveSudoku(std::vector<std::vector<char>> board);