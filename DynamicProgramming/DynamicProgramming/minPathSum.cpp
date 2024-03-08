#include "minPathSum.hpp"

int minPathSum(std::vector<std::vector<int>> grid) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, INT_MAX));
    dp[0][1] = 0;
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    return dp.back().back();
}