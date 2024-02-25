#include "canTraverseAllPairs.hpp"

bool hasCommonFactor(int a, int b) {
    if (a > b) {
        std::swap(a, b);
    }
    int new_mod{ b % a };
    if (new_mod == 0) return true;
    else if (new_mod == 1) return false;
    else return hasCommonFactor(a, new_mod);
}

bool canTraverseAllPairs(std::vector<int>& nums) {
    //Does not work, jumps can go backwards
    for (size_t i = 1; i < nums.size(); i++) {
        if (!(hasCommonFactor(nums[i], nums[i - 1]))) return false;
    }
    return true;
}
