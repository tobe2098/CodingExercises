#include "getAncestors.hpp"

void semirecAncestors(std::vector<bool>& visited, std::vector<std::vector<int>>& rev, std::vector<std::vector<int>>& sol, int index) {
    if (visited[index]) return;
    std::set<int> semi;
    for (int anc : rev[index]) {
        if (visited[anc]) {
            for (int anc2 : sol[anc]) semi.insert(anc2);
        }
        else {
            semirecAncestors(visited, rev, sol, anc);
            for (int anc2 : sol[anc]) semi.insert(anc2);
        }
        semi.insert(anc);
    }
    visited[index] = true;
    sol[index] = std::vector<int>(semi.begin(), semi.end());
}

std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>> edges) {
    std::vector<std::vector<int>> rev(n), sol(n);
    for (std::vector<int>& v : edges) {
        rev[v[1]].push_back(v[0]);
    }
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        semirecAncestors(visited, rev, sol, i);
    }
    return sol;
}