#include "validSudoku.hpp"

bool isValidSudoku(std::vector<std::vector<char>> board) {
    //Brute force is an option here
    //Having maps for boxes and columns and traversing rows would be faster
    size_t size1{ board.size() }, size2{ board[0].size() };
    std::vector<std::map<char, int>> rows(size2);
    std::vector<std::map<char, int>> columns(size1);
    for (size_t i = 0; i < size1; i += 3) {
        for (size_t j = 0; j < size2; j += 3) {
            std::map<char, int> map;
            for (size_t k = i; k < i+3; k++) {
                for (size_t l = j; l < j+3; l++) {
                    char c{ board[k][l] };
                    if (c != '.') {
                        rows[l][c]++;
                        columns[k][c]++;
                        map[c]++;
                    }
                }
            }
            if (std::any_of(map.begin(), map.end(), [](auto& pair) {return pair.second > 1; })) {
                return false;
            }
        }
    }
    for (std::map<char, int>& map : rows) {
        if (std::any_of(map.begin(), map.end(), [](auto& pair) {return pair.second > 1; })) return false;
    }
    for (std::map<char, int>& map : columns) {
        if (std::any_of(map.begin(), map.end(), [](auto& pair) {return pair.second > 1; })) return false;
    }
    return true;
}