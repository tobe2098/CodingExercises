#include "inverseKPairs.hpp"

int kInversePairs(int n, int k) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1));
    for (size_t i = 1; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = j; l >= 0 && l >= j - i + 1; l--) {
                dp[i][j] += dp[i - 1][l];
                dp[i][j] %= (static_cast<int>(1e9) + 7);
            }
        }
    }
    return dp.back().back() % (static_cast<int>(1e9) + 7);
}

int kInversePairsV2(int n, int k)
{
    return 0;
}
