#pragma once
#include <vector>
#include <unordered_map>

// Function to find the root of a set using path compression
int getf(std::vector<int>& f, int x);

// Function to merge two sets and update the frequency
void merge(std::vector<int>& f, std::vector<int>& num, int x, int y);

bool canTraverseAllPairs(std::vector<int>& nums);