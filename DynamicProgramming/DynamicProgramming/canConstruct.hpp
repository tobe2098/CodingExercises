#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
bool canConstructHelper(std::string& construct, std::vector<std::string>& words, std::string replicate, std::unordered_map<std::string, bool>& hashmap);
bool canConstructHelperv2(std::string& construct, std::vector<std::string>& words, std::string replicate, std::unordered_map<std::string, bool>& hashmap);
bool canConstruct(std::string construct, std::vector<std::string> words, std::string replicate = "");
bool canConstructTab(std::string construct, std::vector<std::string> words);
bool canConstructTab2(std::string construct, std::vector<std::string> words);
