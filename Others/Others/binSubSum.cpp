#include "binSubSum.hpp"

int numSubarraysWithSum(std::vector<int> nums, int goal) {
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int numSubarraysWithSum2(std::vector<int> nums, int goal) {
    std::unordered_map<int, int> count;
    count[0] = 1;
    int curr_sum = 0;
    int total_subarrays = 0;

    for (int num : nums) {
        curr_sum += num;
        if (count.find(curr_sum - goal) != count.end()) {
            total_subarrays += count[curr_sum - goal];//This works because you are adding the number of subarray endings from which you can start traversing in order to reach to goal value in your current sum
        }
        count[curr_sum]++;
    }

    return total_subarrays;
}

int atMost(std::vector<int>& nums, int goal) {
    int head, tail = 0, sum = 0, result = 0;
    for (head = 0; head < nums.size(); head++) {
        sum += nums[head];
        while (sum > goal && tail <= head) {
            sum -= nums[tail];
            tail++;
        }
        result += head - tail + 1; //Why does this work? You sum every time you are under goal. That way, for every iteration you are adding all the subarrays that end with the head index and start at tail.
    }
    return result;
}


