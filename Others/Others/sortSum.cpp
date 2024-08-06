#include "sortSum.hpp"

int rangeSum(std::vector<int> nums, int n, int left, int right) {
    std::vector<int> sums, temp1,temp2;
    for (int i = 0; i < nums.size(); i++) {
        int c{ nums[i] };
        for (int s : temp1) {
            temp2.push_back((s + c));
        }
        temp2.push_back(c);
        sums.insert(sums.end(), temp2.begin(), temp2.end());
        temp2.swap(temp1);
        temp2.clear();
    }
    std::sort(sums.begin(), sums.end());
    int sum{};
    for (int i = left; i <= right; i++) {
        sum = (sum + sums[i - 1]) % mod;
    }
    return sum;
}