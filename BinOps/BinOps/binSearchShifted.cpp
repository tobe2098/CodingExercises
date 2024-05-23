#include "binSearchShifted.hpp"

bool search(std::vector<int> nums, int target) {
    int st = 0; int end = nums.size() - 1;
    while (st <= end) {
        int mid = (st + end) / 2;
        if (nums[mid] == target)return true;
        if (nums[st] == nums[mid] && nums[end] == nums[mid])st++, end--;
        else if (nums[mid] >= nums[st]) {
            if (target >= nums[st] && target <= nums[mid]) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        else {
            if (target <= nums[end] && target >= nums[mid]) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }
    return false;
}