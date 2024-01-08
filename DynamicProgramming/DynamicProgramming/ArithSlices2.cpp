#include "ArithSlices2.hpp"

int numberOfArithmeticSlices(std::vector<int> nums) {
    std::unordered_map<int, std::vector<size_t>> nummap;
    for (size_t i = 0; i < nums.size(); i++) nummap[nums[i]].push_back(i);
    std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(nums.size()));
    for (size_t i = 1; i < nums.size(); i++) {
        for (size_t j = i + 1; j < nums.size(); j++) {
            int pred{ 2 * nums[i] - nums[j] };
            for (size_t k : nummap[pred]) {
                if (k < i) {
                    dp[i][j] += dp[k][i] + 1;
                }
                else {
                    break;
                }
            }
        }
    }
    int sum{};
    for (std::vector<int>& row : dp) {
        sum = std::accumulate(row.begin(), row.end(), sum, [](int sum, int var) {return sum + var; });
    }
    return sum;
}