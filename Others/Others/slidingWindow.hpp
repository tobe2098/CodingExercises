#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

int numSubarrayProductLessThanK(std::vector<int> nums, int k);
int numSubarrayProductLessThanKOptimal(std::vector<int> nums, int k);
int numSubarrayProductLessThanKOptimal2(std::vector<int> nums, int k);


int maxSubarrayLength(std::vector<int> nums, int k);

int minSwaps(std::vector<int> nums);