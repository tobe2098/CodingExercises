#include "bestSum.hpp"

std::vector<int> bestSumhelper(std::vector<int> &numbers, int targetSum, std::unordered_map<int, std::vector<int>>& hashmap) {
    if (hashmap.count(targetSum) > 0) return hashmap[targetSum];
    if (targetSum == 0) return {};
    if (targetSum < 0) return { -1 };
    std::vector<int> v;
    for (int n : numbers) {
        v = bestSumhelper(numbers, targetSum - n, hashmap);
        if (v != std::vector<int>{-1}) {
            v.push_back(n);
            return v;
        }
    }
    hashmap[targetSum] = { -1 };
    return hashmap[targetSum];
}

std::vector<int> bestSumhelperv2(std::vector<int>& numbers, int targetSum, std::unordered_map<int, std::vector<int>>& hashmap) {
    if (hashmap.count(targetSum) > 0) return hashmap[targetSum];
    if (targetSum == 0) return {};
    if (targetSum < 0) return { -1 };
    std::vector<int> v, best;
    for (int n : numbers) {
        v = (bestSumhelperv2(numbers, targetSum - n, hashmap));

        if ((best.size() == 0 || v.size() < best.size() - 1) && v != std::vector<int>{-1}) //BANG, best.size()-1 IS THE BIGGEST POSSIBLE SIZE (BUT BAD PRACTICE TO USE OVERFLOW AS A FEATURE)
        {
            v.push_back(n);
            best = v;
        }
    }
    if (best != std::vector<int>{-1}) {
        hashmap[targetSum] = best;
        return best;
    }
    else {
        hashmap[targetSum] = { -1 };
        return { -1 };
    }
}

std::vector<int> bestSum(std::vector<int> numbers, int targetSum) {
    std::unordered_map<int, std::vector<int>> hashmap;
    //std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    return bestSumhelperv2(numbers, targetSum, hashmap);
}

std::vector<int> bestSumTab(std::vector<int> numbers, int targetSum) {
    std::vector<std::vector<int>> dp(targetSum + 1, { -1 });
    dp[0] = {};
    for (int i = 0; i < dp.size(); i++) {
        for (int num : numbers) {
            if (i + num >= dp.size()) continue;
            if (dp[i] != std::vector<int>{-1} && (dp[i + num].size() < dp[i].size()||dp[i+num]==std::vector<int>{-1})) {
                dp[i + num] = dp[i];
                dp[i + num].push_back(num);
            }
        }
    }
    return dp.back();
}