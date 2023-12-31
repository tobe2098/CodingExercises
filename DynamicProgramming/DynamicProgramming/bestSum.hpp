#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
//WRONG
std::vector<int> bestSumhelper(std::vector<int>& numbers, int targetSum, std::unordered_map<int, std::vector<int>>& hashmap);
std::vector<int> bestSumhelperv2(std::vector<int>& numbers, int targetSum, std::unordered_map<int, std::vector<int>>& hashmap);
std::vector<int> bestSum(std::vector<int> numbers, int targetSum);
std::vector<int> bestSumTab(std::vector<int> numbers, int targetSum);