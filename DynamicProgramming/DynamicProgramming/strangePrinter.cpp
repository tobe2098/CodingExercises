#include "strangePrinter.hpp"
int strangePrinter(std::string s) {
    // std::unordered_map<char, std::vector<std::pair<int, int>>>map;
    // int sol{};
    // for (int i=0;i<s.length();i++){
    //     if (map.count(s[i])>0) continue;
    //     int p2=s.length()-1;
    //     while(s[p2]!=s[i])p2--;
    //     map[i].push_back({i,p2});
    // }
    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size()));
    for (int i = dp.size() - 1; i >= 0; i--) {
        for (int j = i; j < dp.size(); j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            int min{ INT_MAX };
            for (int k = i; k < j; k++) {
                // if (s[k]==s[k+1]) continue;
                if (s[k] == s[j]) {
                    int num{ ((i != k) ? dp[i][k] - 1 : 0) + dp[k+1][j] };
                    if (num < min) min = num;
                }
            }
            dp[i][j] = std::min(min, dp[i][j - 1] + (s[j] != s[j - 1]));
            // dp[i][j]=std::min(min, dp[i][j-1]+((j>0)?s[j]!=s[j-1]:0));
        }
    }
    return dp.front().back();
}