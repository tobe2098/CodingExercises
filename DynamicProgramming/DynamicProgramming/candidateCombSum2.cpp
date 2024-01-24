#include "candidateCombSum2.hpp"

std::vector<std::vector<int>> combinationSum2(std::vector<int> candidates, int target) {
    // Only works with LLVM compiler (too smart man)
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

std::vector<std::vector<int>> combinationSum2v2(std::vector<int> candidates, int target) {
    // std::sort(candidates.begin(), candidates.end());
    std::unordered_map<int, int> map;
    for (int num : candidates) map[num]++;
    std::vector<std::vector<std::vector<int>>> dp(target + 1);
    dp[0].push_back(std::vector<int>());
    for (auto& [key, value] : map) {
        for (int i = dp.size() - key - 1; (i >= 0); i--) {
            if (!dp[i].empty()) {
                for (std::vector<int> way : dp[i]) {
                    int  index{ i }, cpy{ value };
                    while (index + key < dp.size() && cpy) {
                        way.push_back(key);
                        dp[index + key].push_back(way);
                        index += key;
                        cpy--;
                    }
                }

            }
        }
    }
    return dp.back();
}

std::vector<std::vector<int>> combinationSum2Set(std::vector<int> candidates, int target){
    //Slower, kind of cheating
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::set<std::vector<int>>> dp(target + 1);
    for (int num : candidates) {
        if (num >= dp.size()) continue;
        for (size_t i = dp.size() - num - 1; i > 0; i--) {
            for (std::vector<int> way : dp[i]) {
                way.push_back(num);
                dp[i + num].insert(way);
            }
        }
        dp[num].insert(std::vector(1, num));
    }
    return std::vector<std::vector<int>>(dp.back().begin(), dp.back().end());
}