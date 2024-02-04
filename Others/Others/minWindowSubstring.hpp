#pragma once
#include <unordered_map>
#include <string>
#include <algorithm>
#include <array>
bool equalOrGreater(std::unordered_map<char, int>& map1, std::unordered_map<char, int>& map2);
std::string minWindow(std::string s, std::string t);
std::string minWindowV2(std::string s, std::string t);