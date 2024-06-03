#include "wordPerm.hpp"

bool isScramble(std::string s1, std::string s2){
        if (s1.length() == 1) return s1 == s2;
        //Recursive
        //To detect if there was (supposedly)
        for (int i = 1; i < s1.length(); i++) {
            //Is swapped 2 calls
            if (isScramble(s1.substr(0, i), s2.substr(s2.length() - i, i)) && isScramble(s1.substr(i, s1.length() - i), s2.substr(0, s2.length() - i))) return true;
            //Is not swapped 2 calls
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.length() - i), s2.substr(i, s2.length() - i))) return true;
        }
        return false;
}

bool isScramble2(std::string s1, std::string s2) {
    std::vector<std::vector<std::vector<int>>> dp(s1.length()+1, std::vector<std::vector<int>>(s1.length(), std::vector<int>(s1.length())));
    for (int length = 1; length <= s1.length(); length++) {
        for (int i = 0; i <= s1.length()-length; i++) for (int j = 0; j <= s1.length()-length; j++) {
            //if (i+length>s1.length()||j+length>s1.length()) break;
            if (length == 1) {
                dp[length][i][j] = (s1[i] == s2[j]);
                continue;
            }
            bool f{ false };
            for (int k =  1; k <  length; k++) {
                int div{ k };
                f = ((dp[div][i][j]) 
                    && (dp[length - div][i + div][j + div])) 
                    || ((dp[div][i][j + length - div]) 
                        && (dp[length - div][i + div][j]));
                if (f) break;
            }
            dp[length][i][j] = f;
        }
    }
    return dp.back().front().front();
}