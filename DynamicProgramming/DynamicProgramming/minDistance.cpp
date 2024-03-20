#include "minDistance.hpp"

int minDistance(std::string word1, std::string word2) {
    int size1 = word1.size(), size2 = word2.size();
    if (word1 == "" || word2 == "") return std::max(size1, size2);
    std::vector<std::vector<int>> dp(word1.size() + 1, std::vector<int>(word2.size() + 1));
    for (int i = 1; i < size2+1; i++) dp[0][i] = dp[0][i - 1] + 1;
    for (int i = 1; i < size1+1; i++) {
        dp[i][0] = dp[i - 1][0] + 1;
        for (int j = 1; j < size2+1; j++) {
            if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + std::min(dp[i][j - 1], std::min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }
    return dp.back().back();
}