#include "kInversions.hpp"

int kInversePairs(int n, int k) { //Study this
    int dp[2][1001] = { 0 };
    dp[0][0] = 1;
    long long mod = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        dp[i & 1][0] = 1;
        long long x = 0;
        for (int j = 1; j <= k; j++) {
            x = (long long)dp[(i - 1) & 1][j] + dp[i & 1][j - 1];
            if (j - i >= 0)
                x += (mod - dp[(i - 1) & 1][j - i]);
            dp[i & 1][j] = x % mod;
        }
    }
    return dp[n & 1][k];
}
