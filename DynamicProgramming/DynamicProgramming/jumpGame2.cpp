#include "jumpGame2.hpp"

int jump(std::vector<int> nums) {
    std::vector<int> dp(nums.size(), INT_MAX);
    dp[0] = 0;
    for (size_t i = 0; i < dp.size(); i++) {
        int n{ dp[i] };
        for (size_t j = 1; j <= nums[i] && i + j < dp.size(); j++) {
            dp[i + j] = std::min(dp[i + j], n + 1);
        }
    }
    return dp.back();
}
