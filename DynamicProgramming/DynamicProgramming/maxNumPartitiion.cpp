#include "maxNumPartitiion.hpp"

int maxSumAfterPartitioning(std::vector<int> arr, int k) {
    std::vector<int> dp(arr.size() + 1);

    for (int i = 1; i < dp.size(); i++) {
        int max{};
        for (int j = i - 1; j >= 0 && j >= i - k; j--) {
            int maxnum{ *std::max_element(arr.begin() + j, arr.begin() + i) };
            max = std::max(max, dp[j] + ((i - j) * maxnum));
        }
        dp[i] = max;
    }
    return dp.back();
}