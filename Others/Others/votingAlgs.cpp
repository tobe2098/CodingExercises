#include "votingAlgs.hpp"

int findJudge(int n, std::vector<std::vector<int>> trust) {
    std::vector<int> arr(n + 1);
    for (std::vector<int>& unit : trust) {
        arr[unit[0]]--;
        arr[unit[1]]++;
    }
    int index{ 1 };
    for (; index < n + 1; index++) {
        if (arr[index] == n - 1) {
            break;
        }
    }
    if (index == n + 1) return -1;
    else return index;
}