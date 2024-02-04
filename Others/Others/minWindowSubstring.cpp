#include "minWindowSubstring.hpp"

bool equalOrGreater(std::unordered_map<char, int>& map1, std::unordered_map<char, int>& map2) {
    for (auto& [key, val] : map1) {
        if (!(map2.contains(key) && map2[key] >= val)) {
            return false;
        }
    }
    return true;
}

std::string minWindow(std::string s, std::string t) {
    //2D dp table, from i to j is the substring of s. In t we only care about 
    //Character count, so we just do a map.
    //O(m+n), we do a single pass, and each i in dp stores the character count until that point (prefix)
    //Then we iterate over n: 
    //Or we iterate over n, store characters, and then we iterate over m, and
    //Sliding window?
    // std::array<int, 26> tmapL{}, tmapU{};
    // for (char c:t){
    //     if (c>'A')
    //     tmap[c-'a']
    // }
    std::unordered_map<char, int> tmap;
    for (char c : t) tmap[c]++;
    std::unordered_map<char, int> tempmap;
    size_t front{}, back{}, bfirst{}, blast{}, sol_size{ INT_MAX };
    bool contains{ false };
    while (back <= s.length() || contains) {
        if (contains) {
            tempmap[s[front]]--;
            front++;
            contains = equalOrGreater(tmap, tempmap);
        }
        else {
            tempmap[s[back]]++;
            back++;
            contains = equalOrGreater(tmap, tempmap);
        }
        if (contains && back - front < sol_size) {
            sol_size = back - front;
            bfirst = front;
            blast = back;
        }
    }
    return std::string(s.begin() + bfirst, s.begin() + blast);;
}
