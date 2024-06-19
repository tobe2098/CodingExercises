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

int bouquets(std::vector<int>& bloomDay, int k, int day) {
    int cnt{}, num{};
    for (int d : bloomDay) {
        if (d <= day) {
            cnt++;
            if (cnt == k) {
                num++;
                cnt = 0;
            }
        }
        else {
            cnt = 0;
        }
    }
    return num;
}

int minDays(std::vector<int> bloomDay, int m, int k) {
    if (static_cast<long>(m) * k > bloomDay.size()) return -1;
    int max{ *std::max_element(bloomDay.begin(), bloomDay.end()) }, min{ *std::min_element(bloomDay.begin(), bloomDay.end()) }, f{ min };
    std::vector<int> visited(max - min+1, -1);
    while (min < max) {
        int mid{ min + (max - min) / 2 };
        int b{ (visited[mid - f] == -1) ? bouquets(bloomDay, k, mid) : visited[mid - f] };
        visited[mid - f] = b;
        if (b >= m) {
            max = mid;
        }
        else if (b < m) {
            min = mid + 1;
        }
    }
    return min;
}