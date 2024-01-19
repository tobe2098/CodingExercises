#include "minFallPath.hpp"

int minFallingPathSum(std::vector<std::vector<int>> matrix) {
    size_t rowSize{ matrix.size() }, colSize{ matrix[0].size() };
    std::vector<std::vector<int>> dp(rowSize, std::vector<int>(colSize, INT_MAX / 2));
    for (size_t i = 0; i < colSize; i++) dp[0][i] = matrix[0][i];
    for (size_t j = 0; j < rowSize; j++) {
        for (int i = 0; i < colSize; i++) {
            if (j + 1 < rowSize) {
                if (i - 1 >= 0) {
                    dp[j + 1][i - 1] = std::min(dp[j + 1][i - 1], dp[j][i] + matrix[j + 1][i - 1]);
                }
                dp[j+1][i] = std::min(dp[j+1][i], dp[j][i] + matrix[j+1][i]);
                if (i + 1 < colSize) {
                    dp[j + 1][i + 1] = std::min(dp[j + 1][i + 1], dp[j][i] + matrix[j + 1][i + 1]);
                }
            }
        }
    }
    return *std::min_element(dp.back().begin(), dp.back().end());
}
