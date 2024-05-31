#include "singleNumber3.hpp"

std::vector<int> singleNumber(std::vector<int> nums) {
    long temp = 0;
    for (int i = 0; i < nums.size(); i++) {
        temp ^= nums[i];
    }
    int res = (temp & temp - 1) ^ temp; //equivalent to (temp& (-temp)), you find the rightmost bit that is set in the number
    int first = 0;
    int second = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (res & nums[i]) {
            first ^= nums[i];
        }
        else {
            second ^= nums[i];
        }
    }
    return { first,second };
}