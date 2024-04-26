#include "longestIdealSubseq.hpp"

int longestIdealString(std::string s, int k) {
    std::array<int, 26> dp{};
    int sol{ 1 };
    for (char c : s) {
        int i{ c - 'a' }, end{ std::min(i + k,25) };
        dp[i]++;
        for (int j = std::max(i - k, 0); j <= end; j++) {
            if (j == i) [[unlikely]]continue;
            dp[i] = std::max(dp[i], dp[j] + 1);
        }
        if (dp[i] > sol)sol = dp[i];
    }
    return sol;
}