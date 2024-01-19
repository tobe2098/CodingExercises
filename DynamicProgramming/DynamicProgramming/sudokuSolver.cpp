#include "sudokuSolver.hpp"

size_t getNextRow(size_t row, size_t col) {//To find the next square without a number
    return row + col / 8;
}

size_t getNextCol(size_t col) {
    return (col + 1) % 9;
}

size_t getGrid(size_t row, size_t col) {
    return 3 * (row / 3) + (col / 3);
}

bool recursiveBacktracking(std::vector<std::vector<char>>& board, size_t row, size_t col, std::array<std::bitset<9>, 9>& rows, std::array<std::bitset<9>, 9>& cols, std::array<std::bitset<9>, 9>& grids) {
    while (row != 9 && board[row][col] != '.') {
        row = getNextRow(row, col);
        col = getNextCol(col);
    }
    if (row == 9) return true;
    size_t currGrid{ getGrid(row, col) };
    std::bitset<9> used{ rows[row] | cols[col] | grids[currGrid] };
    for (size_t i = 0; i < 9; i++) {
        if (!used[i]) {
            rows[row].set(i);
            cols[col].set(i);
            grids[currGrid].set(i);
            board[row][col] = static_cast<char>(i + '1');
            if (recursiveBacktracking(board, row, col, rows, cols, grids)) return true;
            rows[row].reset(i);
            cols[col].reset(i);
            grids[currGrid].reset(i);
        }
    }
    board[row][col] = '.';
    return false;
}

void solveSudoku(std::vector<std::vector<char>> board) {

    std::array<std::bitset<9>, 9> rows{ 0,0,0,0,0,0,0,0,0 };
    std::array<std::bitset<9>, 9> cols{ 0,0,0,0,0,0,0,0,0 };
    std::array<std::bitset<9>, 9> grids{ 0,0,0,0,0,0,0,0,0 };
    for (size_t i = 0; i < 9; i++) {
        for (size_t j = 0; j < 9; j++) {
            char n{ static_cast<char>(board[i][j] - '1') };
            if (n != '.' - '1') {
                rows[i].set(n);
                cols[j].set(n);
                grids[getGrid(i, j)].set(n);
            }
        }
    }
    recursiveBacktracking(board, 0, 0, rows, cols, grids);
}