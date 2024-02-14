#include "rearrangeArray.hpp"

std::vector<int> rearrangeArray(std::vector<int> nums) {
    size_t ptr1{}, ptr2{};
    int pos{}, neg{};
    if (nums[0] < 0) {
        neg = nums[0];
        while (nums[ptr2] < 0) {
            ptr2++;
        }
        nums[0] = nums[ptr2];
        nums[ptr2] = 0;
    }

    while (ptr1 < nums.size()) {
        if (nums[ptr1] > 0) {
            if (pos != 0) {
                std::swap(pos, nums[ptr1]);
            }
            if (ptr1 != 0 && nums[ptr1 - 1] > 0) {
                ptr2 = ptr1 + 1;
                pos = nums[ptr1];
                while (!(nums[ptr2] < 0)) ptr2++;
                nums[ptr1] = nums[ptr2];
                nums[ptr2] = 0;
            }
            else {}
        }
        else if (nums[ptr1] < 0) {
            if (neg != 0) {
                std::swap(neg, nums[ptr1]);
            }
            if (nums[ptr1 - 1] < 0) {
                ptr2 = ptr1 + 1;
                neg = nums[ptr1];
                while (!(nums[ptr2] > 0)) ptr2++;
                nums[ptr1] = nums[ptr2];
                nums[ptr2] = 0;
            }
            else {}
        }
        else {
            if (nums[ptr1 - 1] < 0) {
                if (pos != 0) {
                    nums[ptr1] = pos;
                    pos = 0;
                }
                else {
                    ptr2 = ptr1 + 1;
                    while (!(nums[ptr2] > 0)) ptr2++;
                    nums[ptr1] = nums[ptr2];
                    nums[ptr2] = 0;
                }
            }
            else {
                if (neg != 0) {
                    nums[ptr1] = neg;
                    neg = 0;
                }
                else {
                    ptr2 = ptr1 + 1;
                    while (!(nums[ptr2] < 0)) ptr2++;
                    nums[ptr1] = nums[ptr2];
                    nums[ptr2] = 0;
                }
            }
        }
        ptr1++;
    }
    return nums;
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
