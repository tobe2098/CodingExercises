#include "stoneGames.hpp"

std::string stoneGameIII(std::vector<int> stoneValue) {
    for (int i = stoneValue.size() - 2; i >= 0; i--) stoneValue[i] += stoneValue[i + 1];
    stoneValue.push_back(0);
    std::vector<int> dp(stoneValue.size());
    for (int i = stoneValue.size() - 1; i >= 0; i--) {
        int min{ (i+1<dp.size())?dp[i + 1]:INT_MAX }, idx{ i + 1 };
        if (i + 2 < dp.size()&&dp[i + 2] < min) {
            min = dp[i + 2];
            idx = i + 2;
        }
        if (i + 3 < dp.size()&&dp[i + 3] < min) {
            min = dp[i + 3];
            idx = i + 3;
        }
        dp[i] = stoneValue[i] - ((idx < dp.size()) ? dp[idx] : 0);
    }
    int alice{dp[0]}, bob{stoneValue.front() - alice};
    if (bob == alice) return "Tie";
    else if (bob < alice) return "Alice";
    else return "Bob";
}