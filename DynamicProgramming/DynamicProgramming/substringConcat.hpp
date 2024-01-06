#pragma once
#include <map>
#include <unordered_map>
#include <string>
#include <string_view>
#include <vector>

bool stringCoincides(std::string s, std::vector<std::string>& words, std::map<std::string, int>& counts, std::unordered_map<std::string, bool>& memo);
bool stringCoincides2(std::string_view s, std::vector<std::string>& words, std::map<std::string_view, int>& counts, std::unordered_map<std::string_view, bool>& memo);
std::vector<int> findSubstring(std::string s, std::vector<std::string> words);
std::vector<int> findSubstring2(std::string s, std::vector<std::string> words);