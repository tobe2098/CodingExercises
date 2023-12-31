#include "stringComp2.hpp"

int compLength2(std::string s) {
    int counter{1}, reps{1};
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            reps++;//This should be analogous to reps=2
        }
        else {
            counter++;
            if (reps > 1) {
                counter += std::to_string(reps).size();
                reps = 1;
            }
        }
    }
    if (reps > 1) {
        counter += std::to_string(reps).size();
    }
    return counter;
}

std::string compress(std::string s){
    //This would be a conversion
    std::string compressed;
    compressed.push_back(s[0]);
    int counter{};
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1] && counter > 0) {
            counter++;
        }
        else if (counter > 0) {
            compressed.append(std::to_string(counter));
            counter = 0;
        }
        else {
            compressed.push_back(s[i]);
        }
    }
    return compressed;
}

int getLengthOfOptimalCompressionHelper(std::string s, int k, std::unordered_map<std::string, int>& hashmap) {
    //RECURSIVE VERSION IS NOT WORKING IN TERMS OF SPEED, STH MISSING
    if (hashmap.count(s) > 0) return hashmap[s];
    else if (k <= 0) {
        hashmap[s] = compLength2(s);
        return hashmap[s];
    }
    int count{ 1 }, min_length{ INT_MAX };
    std::string copy;
    for (int i = 0; i < s.size(); i++) {
        copy = s;
        // int j=i+1;
        // int chars;
        // for (;j<copy.size();j++){
            // if (copy[i]!=copy[j]) break;
        // }
        min_length = std::min(getLengthOfOptimalCompressionHelper(copy.erase(i, 1), k - 1, hashmap), min_length);
    }
    hashmap[s] = min_length;
    return min_length;
}

int getLengthOfOptimalCompression(std::string s, int k) {
    //RECURSIVE VERSION IS NOT WORKING IN TERMS OF SPEED, STH MISSING
    //std::vector<std::vector<int>> dp(s.size(), std::vector<int>(k, 0));//PENDING, tabulate
    std::unordered_map<std::string, int> hashmap;
    return getLengthOfOptimalCompressionHelper(s, k, hashmap);
}

int getLengthOfOptimalCompressionTab(std::string s, int k) {
    std::vector<std::vector<int>> dp(s.size()+1, std::vector<int>(k+1, INT_MAX/2));
    //for (int j = 0; j < dp[0].size(); j++) dp[0][j] = 0;
    dp[0][0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j <= k; j++) {
            int count{}, delable{};
            for (int l = i; l >= 1; l--) {
                if (s[i - 1] == s[l - 1]) {
                    count++;
                }
                else {
                    delable++;
                }

                if (j-delable>=0){
                    //std::cout << 1+(count >= 100) ? 3 : (count >= 10) ? 2 : (count >= 2) ? 1 : 0 <<'\n';
                    //std::cout << (dp[l - 1][j - delable] + 1 + ((count >= 100) ? 3 : (count >= 10) ? 2 : (count >= 2) ? 1 : 0)) << '\n';
                    dp[i][j] = std::min(dp[i][j], 
                        (dp[l - 1][j - delable] + 1 + ((count >= 100) ? 3 : (count >= 10) ? 2 : (count >= 2) ? 1 : 0)));//CAREFUL HERE, 1+BOOL IS ALWAYS TRUE WITHOUT()
                    //if (dp[i][j] == 3) throw;
                }

            }
            if (j > 0) {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
            }
        }
    }
    return dp.back().back();
}