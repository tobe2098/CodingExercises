#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
template<typename T1, typename T2>
bool cmp(pair<T1, T2>& a, pair<T1, T2>& b) {
    return a.second < b.second;
};
int findLeastNumOfUniqueInts(std::vector<int> arr, int k);