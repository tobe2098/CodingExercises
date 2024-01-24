#include "candidateCombSum2.hpp"

std::vector<std::vector<int>> combinationSum2(std::vector<int> candidates, int target) {
    // std::sort(candidates.begin(), candidates.end());
    std::unordered_map<int, int> map;
    for (int num : candidates) map[num]++;
    std::vector<std::vector<std::vector<int>>> dp(target + 1);
    dp[0].push_back(std::vector<int>());
    for (auto& [key, value] : map) {
        if (key >= dp.size()) continue;
        for (int i = dp.size() - key - 1; (i >= 0); i--) {
            int cpy{ value };
            if (!dp[i].empty()) {
                while (cpy) {
                    int index{ i + (value - cpy) * key };
                    if (index + key < dp.size()) {
                        for (std::vector<int> way : dp[index]) {
                            way.push_back(key);
                            dp[index + key].push_back(way);
                        }
                    }
                    cpy--;
                }
            }
        }
    }
    return dp.back();
}