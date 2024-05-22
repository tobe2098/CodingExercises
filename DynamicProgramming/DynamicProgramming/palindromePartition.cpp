#include "palindromePartition.hpp"

void backtracking(std::vector<std::vector<int>>& dp, int start, std::vector<std::string> curr, std::string& s, std::vector<std::vector<std::string>>& sol) {
    if (start >= dp.size()) {
        sol.push_back(curr);
        return;
    }
    for (int finish : dp[start]) {
        curr.push_back(s.substr(start, finish - start + 1));
        backtracking(dp, finish + 1, curr, s ,sol);
        curr.pop_back();
    }
}

bool isPalindrome(int i, int j, std::string_view s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::vector<int>> dp(s.size());
    std::vector<std::vector<std::string>> sol;
    for (int i = 0; i < s.size(); i++) for (int j = i; j < s.size(); j++) { 
        if (isPalindrome(i, j, s)) dp[i].push_back(j); 
    }
    backtracking(dp, 0, {}, s, sol);
    return sol;
}