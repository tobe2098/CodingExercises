#pragma once
#include <vector>
#include <queue>
struct GraphNode {
    int id{};
    int mincost{ INT_MAX };
    std::vector<std::pair<GraphNode*, int>> destinations_costs;
    GraphNode(int _id) { id = _id; }
};
int findCheapestPrice(int n, std::vector<std::vector<int>> flights, int src, int dst, int k);