#include "topSort.hpp"

std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>> edges) {
    //Assume a direction inwards towards the direction of centre of gravity.
    std::set<int> erased;
    std::vector<std::set<int>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
        int e1{ edges[i][0] };
        int e2{ edges[i][1] };
        adj[e1].insert(e2);
        adj[e2].insert(e1);
    }
    while (n - erased.size() > 2) {
        std::vector<int> to_erase;
        for (int i = 0; i < n; i++) {
            if (erased.contains(i))continue;
            if (adj[i].size() == 1) to_erase.push_back(i);
        }
        for (int node : to_erase) {
            for (std::set<int>& set : adj) {
                set.erase(node);
            }
            erased.insert(node);
        }
    }
    std::vector<int> sol;
    for (int i = 0; i < n; i++) {
        if (!erased.contains(i)) sol.push_back(i);
    }
    return sol;
}