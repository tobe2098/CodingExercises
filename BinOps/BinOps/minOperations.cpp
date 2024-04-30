#include "minOperations.hpp"

int minOperations(std::vector<int> nums, int k) {
    int res{ nums[0] };
    for (int i = 1; i < nums.size(); i++) {
        res ^= nums[i];
    }
    int bit{ 1 }, sol{ (res & 1) != (k & 1) };
    for (int i = 0; i < 31; i++) {
        bit <<= 1;
        if ((res & bit) != (k & bit)) sol++;
    }
    return sol;
}