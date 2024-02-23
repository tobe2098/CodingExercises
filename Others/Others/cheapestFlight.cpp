#include "cheapestFlight.hpp"
int findCheapestPrice(int n, std::vector<std::vector<int>> flights, int src, int dst, int k) {
    std::vector<GraphNode> nodes;
    for (int i = 0; i < n; i++) nodes.emplace_back(i);
    for (std::vector<int>& f : flights) {
        nodes[f[0]].destinations_costs.push_back({ &(nodes[f[1]]),f[2] });
    }
    int mincost{ -1 };
    nodes[src].mincost = 0;
    std::queue<std::pair<int, int>> q;
    q.push({ src,0 });
    while (k >= 0) {
        size_t currsize{ q.size() };
        for (int i = 0; i < currsize; i++) {
            int curr{ q.front().first }, currcost{ q.front().second };
            q.pop();
            for (auto& [nodeptr, cost] : nodes[curr].destinations_costs) {
                int new_cost{ cost + currcost }, id{ nodeptr->id };
                if (new_cost < nodeptr->mincost) {
                    nodeptr->mincost = new_cost;
                    if (id != dst)q.push({ id, new_cost });
                }
            }
        }
        k--;
    }
    if (nodes[dst].mincost == INT_MAX) return -1;
    else return nodes[dst].mincost;
}