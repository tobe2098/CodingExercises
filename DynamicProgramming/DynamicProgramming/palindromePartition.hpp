#pragma once
#include <vector>
#include <string>

void backtracking(std::vector<std::vector<int>>& dp, int start, std::vector<std::string> curr, std::string& s, std::vector<std::vector<std::string>>& sol);
bool isPalindrome(int i, int j, std::string_view s);

std::vector<std::vector<std::string>> partition(std::string s);