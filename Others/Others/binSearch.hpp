#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
bool searchMatrix(std::vector<std::vector<int>> matrix, int target);
int bouquets(std::vector<int>& bloomDay, int k, int day);
int minDays(std::vector<int> bloomDay, int m, int k);


int numKthPairDistances(std::vector<int>& nums, int bound);
int returnKthDistancePair(std::vector<int>& nums, int k);
int smallestDistancePair(std::vector<int> nums, int k);





class Solution {
    std::vector<int> prefix;
    std::default_random_engine m;
    std::uniform_int_distribution<int> dist;
public:
    Solution(std::vector<int> w) :m(42) {
        std::partial_sum(w.begin(), w.end(), w.begin());
        prefix = w;
        dist = std::uniform_int_distribution<int>(0, prefix.back() - 1);
    }

    int pickIndex() {
        int val{ dist(m) }, l{}, r = prefix.size() - 1;
        while (l < r) {
            int mid{ r - (r - l) / 2 };
            if (prefix[mid] > val) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;

    }
};