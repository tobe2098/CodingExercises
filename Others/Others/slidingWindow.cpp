#include "slidingWindow.hpp"

int numSubarrayProductLessThanK(std::vector<int> nums, int k) {
    if (k == 0) return 0;
    int ptr1{}, ptr2{}, product{ 1 }, count{};
    while ((ptr1 < nums.size())) {
        if (ptr1 >= ptr2) {
            product *= nums[ptr1];
            ptr2 = ptr1 + 1;
        }
        // product=std::reduce(nums.begin()+ptr1,nums.begin()+ptr2,1, std::multiplies<int>{});
        if (product < k) {
            for (int j = ptr1; j < ptr2; j++)count++;
            if (ptr2 == nums.size()) break;
            product *= nums[ptr2];
            ptr2++;
        }
        else {
            product /= nums[ptr1];
            ptr1++;
        }
    }
    return count;
}

int numSubarrayProductLessThanKOptimal(std::vector<int> nums, int k) {
    if (k == 0)
        return 0;
    int n = nums.size(), product = 1, cnt{};
    int l = 0, r = 0;
    while (r < n)
    {
        product *= nums[r++];
        while (l < r && product >= k)
            product /= nums[l++];

        cnt += (r - l);
    }
    return cnt;
}

int numSubarrayProductLessThanKOptimal2(std::vector<int> nums, int k) {
    if (k == 0) return 0;
    long long int rp = 1;
    int res = 0;
    int ri = 0;
    for (int i = 0; i < nums.size(); i++) {
        rp *= nums[i];
        while (rp >= k && i >= ri) {
            rp /= (nums[ri++]);
        }
        res  += (i - ri + 1);
    }
    return res;
}