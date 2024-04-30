#include "dpHell.hpp"

void moveToNextLetters(std::vector<std::vector<int>>& dp, char keychar, std::string_view ring, int i, int j, int prevSteps) {
    if (keychar == ring[j]) {
        dp[i][j] = std::min(dp[i][j], prevSteps + 1);
        return;
    }
    int k{ j };
    while (ring[k] != keychar) {
        k++;
        if (k == ring.length())k = 0;
    }
    int steps{ (k < j) ? (k + static_cast<int>(ring.length()) - j) : k - j };
    dp[i][k] = std::min(dp[i][k], prevSteps+steps + 1);
    k = j;
    while (ring[k] != keychar) {
        k--;
        if (k < 0)k = ring.length() - 1;
    }
    steps = (k > j) ? (j + ring.length() - k) : j - k;
    dp[i][k] = std::min(dp[i][k], prevSteps+steps + 1);
}

int findRotateSteps(std::string ring, std::string key) {
    std::vector<std::vector<int>> dp(key.length(), std::vector<int>(ring.length(), INT_MAX));
    for (int i = 0; i < key.length(); i++) {
        char keychar{ key[i] };
        for (int j = 0; j < ring.length(); j++) {
            if (i > 0 && dp[i - 1][j] != INT_MAX) {
                //Store the steps
                //Move to next two (or one) and add steps there
                moveToNextLetters(dp, keychar, ring, i, j, dp[i - 1][j]);
            }
            else if (i == 0) [[unlikely]] {
                //Move to next two or one and add steps there
                moveToNextLetters(dp, keychar, ring, i, 0, 0);
                break;

                }
        }
    }
    //Return min of last row
    return *std::min_element(dp.back().begin(), dp.back().end());
}