#include "howSum.hpp"

std::vector<int> howSumHelper(std::vector<int>& array, int targetSum, std::unordered_map<int, std::vector<int>>& hashmap) {
    if (hashmap.count(targetSum) > 0) return hashmap[targetSum];
    if (targetSum == 0) return {};
    if (targetSum < 0) return { -1 };
    std::vector<int> v;
    for (int n : array) {
        v = howSumHelper(array, targetSum - n, hashmap);
        if (v != std::vector<int>{-1}) {
            v.push_back(n);
            return v;
        }
    }
    hashmap[targetSum] = { -1 };
    return hashmap[targetSum];
}

std::vector<int> howSum(std::vector<int> array, int targetSum) {
    std::unordered_map<int, std::vector<int>> hashmap;
    return howSumHelper(array, targetSum, hashmap);
}

std::vector<int> howSumTab(std::vector<int> array, int targetSum) {
    std::vector<std::vector<int>> dp(targetSum + 1);
    for (int num : array) {
        if (num < dp.size()) dp[num].push_back(num);
    }
    for (int i = 0; i < dp.size(); i++) {
        for (int num : array) {
            if (i < num) continue;
            if (!dp[i-num].empty()) 
            {
                dp[i] = dp[i - num];
                dp[i].push_back(num);
            }
        }
    }



    return dp.back();
}

std::vector<int> howSumTab2(std::vector<int> array, int targetSum) {
    std::vector<std::vector<int>> dp(targetSum + 1, {-1}); //To replicate the null in js of the teacher
    dp[0] = {};
    for (int i = 0; i < dp.size(); i++) {
        for (int num : array) {
            if (i + num>=dp.size()) continue;
            if (dp[i]!=std::vector<int>{-1}) {
                dp[i+num] = dp[i];
                dp[i+num].push_back(num);
            }
        }
    }
    return dp.back();
}