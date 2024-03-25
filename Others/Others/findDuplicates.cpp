#include "findDuplicates.hpp"

std::vector<int> findDuplicates(std::vector<int> nums) {
    std::set<int> sol;
    for (int i = 0; i < nums.size(); i++) {

        while (nums[i] != i + 1 && nums[i]!= nums[nums[i] - 1]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
        if (i != nums[i] - 1 && nums[i] == nums[nums[i] - 1]) {
            sol.insert(nums[i]);
        }
    }
    return std::vector(sol.begin(), sol.end());
}

std::vector<int> findDuplicates2(std::vector<int> nums){
    std::vector<int>ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
        {
            ans.push_back(abs(nums[i]));
        }
        else {
            nums[abs(nums[i]) - 1] *= -1;
        }

    }
    return ans;
}
