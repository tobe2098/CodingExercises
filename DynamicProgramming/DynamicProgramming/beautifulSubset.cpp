#include "beautifulSubset.hpp"

int backtracking(std::array<int, 1001> cnt, std::vector<int>& nums, int k, int index) {
    if (index == nums.size()) return 1;
    int taken{};
    if (!((nums[index] - k >= 0 && cnt[nums[index] - k] > 0) || (nums[index] + k <= 1000 && cnt[nums[index] + k] > 0))) {
        cnt[nums[index]]++;
        taken = backtracking(cnt, nums, k, index + 1);
        cnt[nums[index]]--;
    }
    int nottaken{ backtracking(cnt, nums, k, index + 1) };
    return taken + nottaken;
}

int beautifulSubsets(std::vector<int>& nums, int k) {
    // std::unordered_map<int, std::vector<int>> map;
    // std::sort(nums.begin(), nums.end());

    std::array<int, 1001> cnt{};

    // } 
    return backtracking(cnt, nums, k, 0) - 1;
}

int beautifulSubsetsBst(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    std::unordered_map<int, std::vector<int>>mp;
    for (auto el : nums) {
        mp[el % k].push_back(el);
    }

    int ans = 1;
    for (auto& [mod_cal, v] : mp) {
        // sort(v.begin(), v.end());
        std::map<int, int> mp2;
        for (auto el : v) mp2[el]++;

        int prev_el = INT_MIN, prevNotTaken = 1, prevTaken = 0, nowNotTaken = 0, nowTaken = 0;
        for (auto& [el, freq] : mp2) {
            int poss_subsets = pow(2, freq) - 1;
            if (prev_el + k == el) {
                nowNotTaken = prevNotTaken + prevTaken;
                nowTaken = prevNotTaken * poss_subsets;
            }
            else {
                nowNotTaken = prevNotTaken + prevTaken;
                nowTaken = (prevNotTaken + prevTaken) * poss_subsets;
            }

            prevNotTaken = nowNotTaken;
            prevTaken = nowTaken;
            prev_el = el;
        }
        ans *= (nowNotTaken + nowTaken);
    }
    return ans - 1;
}
