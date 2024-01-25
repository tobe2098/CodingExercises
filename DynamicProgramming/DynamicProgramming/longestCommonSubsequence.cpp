#include "longestCommonSubsequence.hpp"

int longestCommonSubsequence(std::string text1, std::string text2) {
    std::vector<std::vector<int>> dp(text1.length() + 1, std::vector<int>(text2.length() + 1));
    // dp[0][0]=text1[0]==text2[0];
    for (int i = 1; i < text1.length() + 1; i++) {
        for (int j = 1; j < text2.length() + 1; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] += dp[i - 1][j - 1] + 1; //I missed this!!!! The previous subsequence is there
            }
            else {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp.back().back();
}