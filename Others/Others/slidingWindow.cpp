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

int maxSubarrayLength(std::vector<int> nums, int k) {
    std::unordered_map<int, int> map;
    int ptr1{}, ptr2{};
    int longest{};
    for (; ptr2 < nums.size();) {
        map[nums[ptr2]]++;
        while (ptr1<ptr2 && map[nums[ptr2]]>k) {//Missed this
            map[nums[ptr1]]--;
            ptr1++;
        }
        ptr2++;
        if (ptr2 - ptr1 > longest) longest = ptr2 - ptr1;
        //Sanitize the map
        // if (ptr2%1000==0)for (auto it = map.begin(); it != map.end(); ) {
        //     if (it->second == 0) {
        //         it = map.erase(it);
        //     } else {
        //         ++it;
        //     }
        // }
    }
    return longest;
}

int minSwaps(std::vector<int> nums) {
    if (nums.size() == 1)return 0;
    const int tot{ std::reduce(nums.begin(), nums.end()) };
    // if (tot==0) return 0;
    int p2 = nums.size() - tot + 1, p1{ p2 - 1 };
    int cur{};
    for (int i = 0; i < tot; i++) {
        if (nums[++p1]) cur++;
        if (p1 == nums.size() - 1) p1 = -1;
    }
    cur = tot - cur;
    int min{ cur };
    while (p1 < nums.size()-1) {
        if (!nums[++p1]) cur++;
        if (!nums[p2++]) cur--;
        if (p2 == nums.size())p2 = 0;
        if (cur < min) min = cur;
    }
    return min;
}