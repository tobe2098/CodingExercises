#include "substringConcat.hpp"

bool stringCoincides(std::string s, std::vector<std::string>& words, std::map<std::string, int>& counts, std::unordered_map<std::string, bool>& memo) {
    if (memo.count(s) > 0) return memo[s];
    std::map<std::string, int> countsCopy;
    size_t wordSize{ words[0].size() };

    for (size_t i = 0; i < words.size(); i++) {
        std::string copy{ s.substr(i * wordSize,wordSize) };
        if (counts.count(copy) > 0) {
            countsCopy[copy]++;
        }
        else {
            memo[s] = false;
            return false;
        }
    }
    memo[s] = (counts == countsCopy);
    return  memo[s];
}

bool stringCoincides2(std::string_view s, std::vector<std::string>& words, std::map<std::string_view, int>& counts, std::unordered_map<std::string_view, bool>& memo) {
    if (memo.count(s) > 0) return memo[s];
    std::map<std::string_view, int> countsCopy;
    size_t wordSize{ words[0].size() }, size{ words.size() };

    for (size_t i = 0; i < size; i++) {
        std::string_view copy{ s.substr(i * wordSize, wordSize) };
        if (counts.count(copy) > 0) {
            countsCopy[copy]++;
        }
        else {
            memo[s] = false;
            return false;
        }
    }
    memo[s] = (counts == countsCopy);
    return  memo[s];
}

std::vector<int> findSubstring(std::string s, std::vector<std::string> words) {
    size_t len { words.size()* words[0].size() };
if (s.length() < len) return {};
std::vector<int> globalSolution;
std::map<std::string, int> counts;
std::unordered_map<std::string, bool> memo;
for (std::string word : words) counts[word]++;
size_t  maxlen{ s.length() - len };
for (size_t i = 0; i <= maxlen; i++) {
    // std::string sub {s.substr(i,len)};
    if (stringCoincides(s.substr(i, len), words, counts, memo)) globalSolution.push_back(i);
}
//There is a max, you cannot reuse words. It has to be of ALL the words. You have to scan chunks of strlen()*size()
return globalSolution;
    }

std::vector<int> findSubstring2(std::string s, std::vector<std::string> words) {
    size_t len{ words.size() * words[0].size() };
    if (s.length() < len) return {};
    std::vector<int> globalSolution;
    std::map<std::string_view, int> counts;
    std::unordered_map<std::string_view, bool> memo;
    for (std::string_view word : words) counts[word]++;
    size_t  maxlen{ s.length() - len };
    for (size_t i = 0; i <= maxlen; i++) {
        // std::string sub {s.substr(i,len)};
        if (stringCoincides2(std::string_view(s).substr(i, len), words, counts, memo)) globalSolution.push_back(i);
    }
    //There is a max, you cannot reuse words. It has to be of ALL the words. You have to scan chunks of strlen()*size()
    return globalSolution;
}