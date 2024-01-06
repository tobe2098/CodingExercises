#pragma once
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <array>
struct Task {
    int startTime;
    int endTime;
    int profit;

    Task(int startTime, int endTime, int profit) :startTime{ startTime }, endTime{ endTime }, profit{ profit } {}
    bool operator<(const Task& other) const {
        return startTime < other.startTime;
    }
};
int jobScheduling(std::vector<int> startTime, std::vector<int> endTime, std::vector<int> profit);
int jobScheduling2(std::vector<int> startTime, std::vector<int> endTime, std::vector<int> profit);

namespace job4 {
    int jobScheduling4(std::vector<int> startTime, std::vector<int> endTime, std::vector<int> profit);
    int jobScheduling3(std::vector<int> startTime, std::vector<int> endTime, std::vector<int> profit);
}
