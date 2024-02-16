#include "findLeastNumUniqInts.hpp"

int findLeastNumOfUniqueInts(std::vector<int> arr, int k) {
    //This solution works, not the fastest not the slowest
    std::unordered_map<int, int> map;
    for (int num : arr) map[num]++;
    std::vector<std::pair<int, int>> newmap(map.begin(), map.end());
    std::sort(newmap.begin(), newmap.end(), cmp<int, int>);
    int size{ static_cast<int>(newmap.size()) };
    for (auto& [key, value] : newmap) {
        if (value <= k) {
            k -= value;
            size--;
        }
        else {
            break;
        }
    }
    return size;
}

int findLeastNumOfUniqueIntsFaster(std::vector<int> arr, int k) {
    std::sort(arr.begin(), arr.end());
    std::vector<int> V = { 1 };
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) {
            V.back()++;
        }
        else {
            V.push_back(1);
        }
    }

    std::sort(V.begin(), V.end());
    int ans = V.size();
    for (int i = 0; i < V.size(); i++) {
        if (V[i] <= k) {
            ans--;
            k -= V[i];
        }
        else {
            break;
        }
    }
    return ans;
}