#include "islands.hpp"

int numIslands(std::vector<std::vector<char>> grid) {
    int size1 = grid.size(), size2 = grid[0].size();
    std::vector<std::vector<int>> island_id(size1, std::vector<int>(size2));
    std::unordered_map<int, int> links;
    int no_island{}, id{};
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (grid[i][j] == '0') continue;
            else if ((i == 0 || island_id[i - 1][j] == 0) && (j == 0 || island_id[i][j - 1] == 0)) { island_id[i][j] = ++id; no_island++; }
            else if ((i > 0 && island_id[i - 1][j] != 0) && (j > 0 && island_id[i][j - 1] != 0)) {
                if (island_id[i][j - 1] != island_id[i - 1][j] && (links[island_id[i][j - 1]] != island_id[i - 1][j] && links[island_id[i - 1][j]] != island_id[i][j - 1])) {
                    //Merge
                    no_island--;
                    island_id[i][j] = island_id[i][j - 1];
                    links[island_id[i][j]] = island_id[i - 1][j];
                    links[island_id[i - 1][j]] = island_id[i][j - 1];
                }
                else {
                    island_id[i][j] = island_id[i][j - 1];
                }
            }
            else {
                if (i > 0 && island_id[i - 1][j] != 0) {
                    island_id[i][j] = island_id[i - 1][j];
                }
                else {
                    island_id[i][j] = island_id[i][j - 1];
                }
            }
        }
    }
    return no_island;
}