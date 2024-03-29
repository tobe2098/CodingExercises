#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
template<typename T1, typename T2>
bool cmp(std::pair<T1, T2>& a, std::pair<T1, T2>& b) {
    return a.second < b.second;
};
int findLeastNumOfUniqueInts(std::vector<int> arr, int k);
int findLeastNumOfUniqueIntsFaster(std::vector<int> arr, int k);