#include "minKFlips.hpp"

int minKBitFlips(std::vector<int> nums, int k) {
    int solution{}, p1{}, p2{ k - 1 };
    while (p2 < nums.size()) {
        if (nums[p1] == 0) {
            solution++;
            for (int i = p1; i <= p2; i++) {
                nums[i] ^= 1;
            }
        }
        p2++;
        p1++;
    }
    for (int j = nums.size() - 1; j >= (int)nums.size() - k; j--) {
        if (nums[j] == 0) return -1;
    }
    return solution;
}