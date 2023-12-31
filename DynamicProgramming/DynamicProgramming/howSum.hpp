#pragma once
#include <vector>
#include <unordered_map>
std::vector<int> howSumHelper(std::vector<int>& array, int targetSum, std::unordered_map<int, std::vector<int>>& hashmap);
std::vector<int> howSum(std::vector<int> array, int targetSum);
std::vector<int> howSumTab(std::vector<int> array, int targetSum);
std::vector<int> howSumTab2(std::vector<int> array, int targetSum);