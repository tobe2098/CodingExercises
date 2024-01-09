#include "binSearch1.hpp"

std::vector<int> searchRange(std::vector<int> nums, int target) {
    size_t i{}, j{ nums.size() - 1 };
    while (i != j) {
        size_t m{ j - (j - i) / 2 };
        if (nums[m] < target) {
            //Right if lower
            i = m ;
        }
        else {
            //Left if higher or equal
            j = m-1;
        }
    }
    size_t k{}, l{ nums.size() - 1 };
    while (k != l) {
        size_t m{ l - (l - k) / 2 };
        if (nums[m] <= target) {
            //Right if lower
            k = m ;
        }
        else {
            //Left if higher or equal
            l = m-1;
        }
    }
    if (nums[i] != target && nums[i + 1] != target) return { -1, -1 };
    //Now it either is the target or the one before
    return{ static_cast<int>(i + (nums[i] != target)), static_cast<int>(k - (nums[k] != target)) };
}