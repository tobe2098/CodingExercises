#include "binSearch.hpp"

bool searchMatrix(std::vector<std::vector<int>> matrix, int target) {
    //Using Hermann Bottenbruch's method
    int p1{}, p2 = matrix.size() - 1;
    while (p1 != p2) {
        int m = p1 + ((p2 - p1+1) / 2);
        if (matrix[m][0] <= target) {
            p1 = m;
        }
        else {
            p2 = m-1;
        } 
    }
    int index = p1;
    p1 = 0;
    p2 = matrix[index].size() - 1;
    while (p1 != p2) {
        int m = p1 + (p2 - p1+1) / 2;
        if (matrix[index][m] <= target) {
            p1 = m;
        }
        else {
            p2 = m-1;
        }
    }
    if (matrix[index][p1] == target)return true;
    return false;
}