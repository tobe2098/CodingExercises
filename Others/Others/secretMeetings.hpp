#pragma once
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
struct SGraphNode {
    int id{};
    std::unordered_map<int, std::vector<int>> meets_time;
    SGraphNode(int n) { id = n; }
};

std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson);