#include "fib.hpp"

unsigned long long fibtab(int num) {
    std::vector<unsigned long long> dp (num+1, 0);
    dp[1] = 1;
    for (int i = 1; i < dp.size(); i++) {
        if (i + 1 < dp.size()) {
            dp[i + 1] += dp[i];
        }
        if (i + 2 < dp.size()) {
            dp[i + 2] += dp[i];
        }
    }
    return dp.back();
}
