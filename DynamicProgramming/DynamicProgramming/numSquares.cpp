#include "numSquares.hpp"

int numSquares(int n) {
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < std::sqrt(n); i++) {
        int sqr{ static_cast<int>(std::pow(i,2)) };
        for (int j = sqr; j < dp.size(); j++) {
            dp[j] = std::min(dp[j], dp[j - sqr] + 1);
        }
    }
    return dp.back();
}