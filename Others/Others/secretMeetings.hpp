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
//Problem 2092, go visit the more optimal solutions
std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson);

std::vector<int> findAllPeople2(int n, std::vector<std::vector<int>>& meetings, int firstPerson);