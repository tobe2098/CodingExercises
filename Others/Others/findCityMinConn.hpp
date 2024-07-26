#pragma once
#include <vector>
#include <array>
#include <queue>
struct CompareArray {
    bool operator()(const std::array<int, 3>& a, const std::array<int, 3>& b) const {
        // Custom comparison logic; for example, compare based on the sum of elements
        return(a[2] > b[2]);
    }
};
void relax(std::vector<std::vector<int>>& distances, int distanceThreshold, int currdist);
int findTheCity(int n, std::vector<std::vector<int>> edges, int distanceThreshold);