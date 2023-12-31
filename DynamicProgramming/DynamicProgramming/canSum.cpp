#include "canSum.hpp"

bool canSumHelper(std::vector<int>& array, int targetSum, std::unordered_map<int, bool>& hashmap) {
    if (hashmap.count(targetSum) > 0) return hashmap[targetSum];
    if (targetSum == 0) return true;
    else if (targetSum < 0) return false;
    for (int n : array) {
        if (n <= targetSum && canSumHelper(array, targetSum - n, hashmap)) {
            return true;
        }
    }
    hashmap[targetSum] = false;
    return false;
}

bool canSum(std::vector<int> array, int targetSum) {
    std::unordered_map<int, bool> hashmap;
    return canSumHelper(array, targetSum, hashmap);
}

bool canSumTab(std::vector<int> array, int targetSum) {
    //My version (cost should be the same as the other version, maybe faster bc of parallel)
    std::vector<bool> dp(targetSum+1, false);
    for (int i = 0; i < dp.size(); i++) {
        dp[i] = std::any_of(array.cbegin(), array.cend(), [i, dp](int num) { return i==num || (i>=num&&dp[i - num]); });
        /*for (int num : array) {
            dp[i] = dp[i] || (i == num || (i >= num && dp[i - num]));
        }*/
    }
    
    return dp.back();
}

bool canSumTab2(std::vector<int> array, int targetSum) {
    //Version of the video guy
    std::vector<bool> dp(targetSum + 1, false);
    dp[0] = true;
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i]) {
            for (int num : array) {
                if (num + i < dp.size()) dp[i + num] = true;
            }
        }
    }
    return dp.back();
}

