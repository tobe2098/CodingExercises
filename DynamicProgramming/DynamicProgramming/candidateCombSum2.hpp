#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
std::vector<std::vector<int>> combinationSum2(std::vector<int> candidates, int target);
std::vector<std::vector<int>> combinationSum2v2(std::vector<int> candidates, int target);//This one now works with LeetCode too
std::vector<std::vector<int>> combinationSum2Set(std::vector<int> candidates, int target);