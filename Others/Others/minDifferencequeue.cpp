#include "minDifferencequeue.hpp"

int minDifference(std::vector<int> nums) {
    if (nums.size() <= 3) return 0;
    std::sort(nums.begin(), nums.end());
    int p1{}, p2 = nums.size() - 4, min{INT_MAX};
    while (p2 < nums.size()) {
        min = std::min(nums[p2] - nums[p1], min);
        p1++;
        p2++;
    }
    return min;
}