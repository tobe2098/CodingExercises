#include "uniquePathWithObstacles.hpp"

int uniquePathsWithObstacles(std::vector<std::vector<int>> obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n));
    dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i != 0 || j != 0) [[likely]] {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = ((i > 0) ? dp[i - 1][j] : 0) + ((j > 0) ? dp[i][j - 1] : 0);
                }
        }
    }
    return dp.back().back();
}