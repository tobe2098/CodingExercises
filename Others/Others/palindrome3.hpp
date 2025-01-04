#pragma once

#include <vector>
#include <string>
#include <unordered_map>

int countPalindromicSubsequence(std::string s) {
    std::vector<std::vector<std::pair<int, int>>> prefix(s.size(), std::vector<std::pair<int, int>>(26, { 0,-1 }));
    std::unordered_map<int, std::unordered_map<int, int>> map;
    int sol{};
    for (int i = 0; i < s.size(); i++) {
        int c{ s[i] - 'a' };
        if (i > 0)prefix[i] = prefix[i - 1];
        prefix[i][c].first++;
        int old{ prefix[i][c].second };
        prefix[i][c].second = i;
        if (old == -1) continue;
        for (int j = 0; j < 26; j++) {
            int cnt{ prefix[i][j].first - prefix[old][j].first };
            if (cnt == 0) continue;
            if (j == c) {
                map[c][c]++;
                if (map[c][c] == 2) {
                    sol++;
                }
            }
            else {
                map[c][j]++;
                if (map[c][j] == 1) sol++;
            }
        }
    }
    return sol;
}
