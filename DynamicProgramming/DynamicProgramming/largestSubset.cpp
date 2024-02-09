#include "largestSubset.hpp"

std::vector<int> largestDivisibleSubset(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> dp(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i ; j >= 0; j--) {
            if (nums[i] % nums[j] == 0 && dp[i].size() <= dp[j].size()) {
                dp[i] = dp[j];
                dp[i].push_back(nums[i]);
            }
        }
    }
    size_t size_max{1}, idx{};
    for (size_t i = 1; i < dp.size(); i++) {
        if (size_max < dp[i].size()) {
            size_max = dp[i].size();
            idx = i;
        }
    }
        
    return dp[idx];
}