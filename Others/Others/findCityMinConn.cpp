#include "findCityMinConn.hpp"

void relax(std::vector<std::vector<int>>& distances, int distanceThreshold, int currdist,int n, int i, int j) {
    if (currdist > distanceThreshold)
        return;
    // First we do the edge itself, then we do other connected
    distances[i][j] = currdist;
    distances[j][i] = currdist;
    for (int iti = 0; iti < n; iti++) {
        if (iti == i || iti == j)
            continue;
        //This relaxation has to go on recursively
        if (distances[i][iti] != INT_MAX &&
            currdist + distances[i][iti] <= distanceThreshold &&
            currdist + distances[i][iti] < distances[j][iti]) {
            relax(distances, distanceThreshold, currdist + distances[i][iti], n, j, iti);
        }
        else if (distances[j][iti] != INT_MAX &&
            currdist + distances[j][iti] <= distanceThreshold &&
            currdist + distances[j][iti] < distances[i][iti]) {
            relax(distances, distanceThreshold, currdist + distances[j][iti], n, i, iti);
        }
    }
}

int findTheCity(int n, std::vector<std::vector<int>> edges, int distanceThreshold) {
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>,
        std::greater<std::array<int, 3>>>
        min_q;
    for (std::vector<int>& e : edges) {
        min_q.push({ e[2], e[1], e[0] });
    }
    std::vector<std::vector<int>> distances(n,
        std::vector<int>(n, INT_MAX));
    for (int t = 0; t < edges.size(); t++) {
        std::array<int, 3> a{ min_q.top() };
        auto& [w, j, i] = a;
        min_q.pop();
        if (w > distanceThreshold)
            break;
        // First we do the edge itself, then we do other connected
        if (distances[i][j] > w) {
            relax(distances, distanceThreshold, w, n, j, i);
        }
        
    }
    int min{ INT_MAX }, id{};
    for (int i = 0; i < n; i++) {
        int c{};
        for (int j = 0; j < n; j++) {
            if (distances[i][j] <= distanceThreshold)
                c++;
        }
        if (c <= min) {
            min = c;
            id = i;
        }
    }
    return id;
}