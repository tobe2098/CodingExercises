#include "seqDigits.hpp"

std::vector<int> sequentialDigits(int low, int high) {
    size_t hgs{ std::to_string(high).length() };
    std::vector<std::string> nums(8);
    std::vector<int> presol;
    for (int i = 0; i < 8; i++) {
        nums[i].push_back(i + '1');
        nums[i].push_back(nums[i][0] + 1);
        presol.push_back(std::stoi(nums[i]));
    }
    size_t lastSize{ 2 };
    while (lastSize <= hgs) {
        for (int i = 0; i < 8; i++) {
            if ((nums[i][nums[i].length() - 1] + 1) <= '9') {
                nums[i].push_back(nums[i][lastSize - 1] + 1);
                presol.push_back(std::stoi(nums[i]));
            }
        }
        lastSize++;
    }
    std::vector<int> sol;
    std::copy_if(presol.begin(), presol.end(), std::back_inserter(sol), [low, high](int num) {
        return (num >= low) && num <= high;
        });
    return sol;
}