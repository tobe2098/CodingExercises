#include "numSubmatrixSumTarget.hpp"

int noTargetsInArray(std::vector<int>& arr, int target) {//Review
    int x = 0, y = 0, count = 0, sum = 0;

    while (y < arr.size()) {
        if (sum < target) {
            sum += arr[y];
            y++;
        }
        else if (sum > target) {
            sum -= arr[x];
            x++;
        }
        else {
            count++;
            sum -= arr[x];
            x++;
        }
    }

    // Handle the case where the last element equals the target
    while (x < arr.size() && sum >= target) {
        if (sum == target) {
            count++;
        }
        sum -= arr[x];
        x++;
    }

    return count;
}

int noTargetsInArrayV2(std::vector<int>& arr, int target) {
    std::unordered_map<int, int> map;
    int count{};
    int sum{};
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if (sum == target) {
            ++count;
        }
        if (map.count(sum - target) > 0) count += map[sum - target];

        ++map[sum];
    }
    return count;
}

int numSubmatrixSumTarget(std::vector<std::vector<int>> matrix, int target) {
    std::vector<int> holder(matrix[0].size());
    int res{};
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i; j < matrix.size(); j++) {
            for (size_t k = 0; k < holder.size(); k++) holder[k] += matrix[j][k];
            res += noTargetsInArray(holder, target);
        }
        std::fill(holder.begin(), holder.end(), 0);
    }
    return res;
}
