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

std::vector<std::vector<int>> combinationSumv2(std::vector<int> candidates, int target) {
    std::vector<std::vector<std::vector<int>>> dp(target + 1);
    size_t size{ dp.size() };
    for (int num : candidates) {
        dp[num].push_back(std::vector<int>(1, num));
        for (size_t i = 0; i < size; i++) {
            if (i+num< size && !dp[i].empty()) {
                std::vector<std::vector<int>> temp;
                std::copy(dp[i].begin(), dp[i].end(), std::back_inserter(temp));
                for (std::vector<int>& way : temp) {
                    way.push_back(num);
                }
                std::copy(temp.begin(), temp.end(), std::back_inserter(dp[i + num]));
            }            
        }
    }
    return dp.back();
}