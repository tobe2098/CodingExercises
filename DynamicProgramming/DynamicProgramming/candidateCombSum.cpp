#include "candidateCombSum.hpp"

std::vector<std::vector<int>> combinationSum(std::vector<int> candidates, int target) {
    std::vector<std::set<std::vector<int>>> dp(target + 1);
    for (int i = 1; i < dp.size(); i++) {
        for (int num : candidates) {
            if (i - num < 0) continue;
            else if (i - num == 0) {
                dp[i].insert(std::vector<int>(1, num));
            }
            else if (!dp[i - num].empty()) {
                std::vector<std::vector<int>> temp;
                std::copy(dp[i - num].begin(), dp[i - num].end(), std::back_inserter(temp));
                for (std::vector<int>& way : temp) {
                    way.push_back(num);
                    std::sort(way.begin(), way.end());
                }
                dp[i].insert(temp.begin(), temp.end());
            }
        }
    }
    return std::vector<std::vector<int>>(dp.back().begin(), dp.back().end());
}