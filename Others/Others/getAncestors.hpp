#pragma once
#include <vector>
#include <set>

void semirecAncestors(std::vector<bool>& visited, std::vector<std::vector<int>>& rev, std::vector<std::vector<int>>& sol, int index);
std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>> edges);