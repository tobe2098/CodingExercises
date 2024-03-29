#include "countSubarrays.hpp"

long long countSubarrays(std::vector<int> nums, int k) {
    //Why does it not work?
    std::unordered_map<int, int> map;
    int ptr1{}, ptr2{}, max{};
    long long count{};
    while (ptr2 < nums.size()) {
        map[nums[ptr2]]++;
        if (nums[ptr2] > max) max = nums[ptr2];
        ptr2++;
        std::unordered_map<int, int> map2 = map;
        int submax{ max };
        for (int ptr1 = 0; ptr1 < ptr2; ptr1++) {
            if (map2[submax] == 0) {
                max = *std::max_element(nums.begin() + ptr1, nums.begin() + ptr2);
            }
            if (map2[submax] >= k) count++;
            map2[nums[ptr1]]--;
            ptr1++;
        }
    }
    return count;
}

long long countSubarrays2(std::vector<int> nums, int k) {
    //This works, but only for max of subarray, not for the max of nums
    std::unordered_map<int, int> plc;
    std::unordered_map<int, std::unordered_map<int, int>> prefix;
    prefix[-1] = plc;
    for (int i = 0; i < nums.size(); i++) {
        plc[nums[i]]++;
        prefix[i] = plc;
    }
    int ptr1{}, ptr2{}, max{}, subc{};
    long long count{};
    for (int ptr2 = 0; ptr2 < nums.size(); ptr2++) {
        for (int ptr1 = -1; ptr1 < ptr2; ptr1++) {
            max = *std::max_element(nums.begin() + (ptr1 + 1), nums.begin() + (ptr2 + 1));
            if (prefix[ptr1].count(max) == 0) {
                subc = prefix[ptr2][max];
            }
            else {
                subc = prefix[ptr2][max] - prefix[ptr1][max];
            }
            if (subc >= k) count++;
        }
    }
    return count;
}

long long countSubarraysTrue(std::vector<int> nums, int k) {
    int max = *std::max_element(nums.begin(), nums.end());
    int count{};
    long long sol{};
    int ptr1{-1};
    for (int ptr2 = 0; ptr2 < nums.size(); ptr2++) {
        if (nums[ptr2] == max) count++;
        while (ptr1 < ptr2 && count >= k) {
            sol += nums.size() - ptr2;
            ptr1++;
            if (nums[ptr1] == max) count--;
        }
    }
    return sol;
}
