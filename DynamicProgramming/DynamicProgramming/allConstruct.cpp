#include "allConstruct.hpp"
std::vector< std::vector<std::string> > allConstructHelper(std::string target, std::vector<std::string> words, std::unordered_map<std::string, std::vector<std::vector<std::string>>>& hashmap)
{
    if (target == "") return { {} };
    else if (hashmap.count(target) > 0)return hashmap[target];
    std::vector<std::vector<std::string>> sol{}, plc{};
    for (std::string word : words) {
        if (word == target || (target.find(word) == 0)) {
            plc = allConstructHelper(target.substr(word.size(), target.size()), words, hashmap);
            if (std::vector<std::vector<std::string>>{} != plc) {
                for (std::vector<std::string>& ind : plc) {
                    ind.push_back(word);
                }
                sol.insert(sol.end(), plc.begin(), plc.end());
            }
        }
    }
    hashmap[target] = sol;
    return sol;
}

std::vector<std::vector<std::string>> allConstruct(std::string target, std::vector<std::string> words)
{
    std::unordered_map < std::string, std::vector<std::vector<std::string>>>hashmap;
    allConstructHelper(target, words, hashmap);
    
    for (std::vector<std::string>& ind : hashmap[target]) {
        std::reverse(ind.begin(), ind.end());
    }

    return hashmap[target];
}

std::vector<std::vector<std::string>> allConstructTab(std::string target, std::vector<std::string> words) {
    //Done by me too :)
    std::vector<std::vector <std::vector< std::string >> > dp(target.size() + 1);
    dp[0].push_back({});
    for (int i = 0; i < dp.size(); i++) {
        for (std::string& word:words) {
            if (!dp[i].empty()&&i+word.size()<dp.size()&&word==target.substr(i, word.size())) {
                dp[i+word.size()].insert(dp[i+word.size()].end(), dp[i].begin(), dp[i].end());
                for (std::vector<std::string>& way : dp[i + word.size()]) {
                    way.push_back(word);
                }
            }
        }
    }
    return dp.back();
}
