#include "maximumEdgeScore.hpp"

long long maximumImportance(int n, std::vector<std::vector<int>> roads) {
    std::vector<int> occ;
    for (std::vector<int>& r : roads) {
        occ[r[0]]++;
        occ[r[1]]++;
    }
    std::sort(occ.begin(), occ.end());
    int i{ 1 };
    long long sol{};
    for (int count : occ) {
        sol += count * i;
        i++;
    }
    return sol;
}