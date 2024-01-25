#include "longestCommonSubsequence.hpp"

int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<std::vector<int>> dp(text1.length(), std::vector<int>(text2.length()));
    // dp[0][0]=text1[0]==text2[0];
    for (int i = 0; i < text1.length(); i++) {
        for (int j = 0; j < text2.length(); j++) {
            dp[i][j] =std::max((j > 0) ? dp[i][j - 1]:0, (i > 0) ? dp[i - 1][j] : 0);
            if (text1[i] == text2[j]) {
                dp[i][j]++;
            }
        }
    }
    return dp.back().back();
}