#pragma once
#include <map>
#include <unordered_map>
#include <string>
#include <string_view>
#include <vector>

bool stringCoincides(std::string s, std::vector<std::string>& words, std::map<std::string, int>& counts, std::unordered_map<std::string, bool>& memo);

std::vector<int> findSubstring(std::string s, std::vector<std::string> words);