#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
bool canSum(std::vector<int> array, int targetSum);
bool canSumHelper(std::vector<int>& array, int targetSum, std::unordered_map<int, bool>& hashmap);
bool canSumTab(std::vector<int> array, int targetSum);
bool canSumTab2(std::vector<int> array, int targetSum);