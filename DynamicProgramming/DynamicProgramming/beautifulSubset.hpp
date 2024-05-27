#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <array>
int backtracking(std::array<int, 1001> cnt, std::vector<int>& nums, int k, int index);
int beautifulSubsets(std::vector<int>& nums, int k);
int beautifulSubsetsBst(std::vector<int>& nums, int k);