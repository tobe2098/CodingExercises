#pragma once

#include "mathOptimized.hpp"
#include <vector>
#include <array>

std::vector<int> mergeSortInPlace(std::vector<int> nums);
std::vector<int> mergeSortWithONspace(std::vector<int> nums);
std::vector<int> bottomUpMergeSort(std::vector<int> nums);
void mergeSort(std::vector<int>& nums, int start, int end);
void mergeSort2(std::vector<int>& nums, int start, int end, std::vector<int>& temp);
void merge(std::vector<int>& nums, int left, int mid, int right, std::vector<int>& temp);

void radix(std::vector<int>& nums, int bits, int min_num, int mask, int shifts, std::vector <std::vector< int >>& buckets);
std::vector<int> radixSortFixed(std::vector<int> nums); 
std::vector<int> radixSortAll(std::vector<int> nums);

std::vector<int> quickSortWrapper(std::vector<int> nums);
void quicksortInPlace(std::vector<int>& nums, int start, int end);