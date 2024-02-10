#include "rotate.hpp"

void rotate(std::vector<std::vector<int>>& matrix) {
    int n{ static_cast<int>(matrix.size()) };
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n-i - 1; j++) {
            int idx1{ j }, idx2{ (n - i - 1) % n };
            std::swap(matrix[i][j], matrix[idx1][idx2]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            int idx1{ (n - i - 1) % n }, idx2{ (n - j - 1) % n };
            std::swap(matrix[i][j], matrix[idx1][idx2]);
        }
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = i; j < n - 1 - i; j++) {
            int idx1{ (n - j - 1) % n }, idx2{ i };
            std::swap(matrix[i][j], matrix[idx1][idx2]);
        }
    }
}