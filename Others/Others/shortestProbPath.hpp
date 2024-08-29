#pragma once
#include <vector>
#include <queue>
void dijkstra(std::vector<std::vector<std::pair<double, int>>>& adj, std::vector<double>& dist, int start, int end) {
    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>> pq;
    dist[start] = 1.0;
    pq.push({ 1.0, start });
    while (!pq.empty()) {
        auto [p, node] = pq.top();
        if (node == end) return;
        pq.pop();
        if (p < dist[node]) continue;
        for (auto& [p2, node2] : adj[node]) {
            if (p2 * p > dist[node2]) {
                dist[node2] = p2 * p;
                pq.push({ p2 * p,node2 });
            }
        }
    }
}
double maxProbability(int n, std::vector<std::vector<int>> edges, std::vector<double> succProb, int start_node, int end_node) {
    std::vector<double> dist(n);
    std::vector<std::vector<std::pair<double, int>>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back({ succProb[i],edges[i][1] });
        adj[edges[i][1]].push_back({ succProb[i],edges[i][0] });
    }
    dijkstra(adj, dist, start_node, end_node);
    return dist[end_node];
}
