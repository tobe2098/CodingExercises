#include "rearrangeArray.hpp"

std::vector<int> rearrangeArray(std::vector<int> nums) {
    int n = nums.size();
    std::vector<int> ans(n);
    int i = 0, j = 1;
    for (int k = 0; k < n; k++) {
        if (nums[k] > 0) {
            ans[i] = nums[k];
            i += 2;
        }
        else {
            ans[j] = nums[k];
            j += 2;
        }
    }
    return ans;
}
std::vector<int> rearrangeArrayV2(std::vector<int> nums) {
    std::vector<int> pos, neg;
    for (int num : nums) {
        if (num > 0) pos.push_back(num);
        else neg.push_back(num);
    }
    nums.clear();
    for (size_t i = 0; i < pos.size(); i++) {
        nums.push_back(pos[i]);
        nums.push_back(neg[i]);
    }
    return nums;
}
