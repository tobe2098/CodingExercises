#include "numMagicSquares.hpp"

int isMagic(std::vector<std::vector<int>>& grid, int x, int y){
        if (x+2>=grid.size() || y+2>=grid[x].size()) return 0;
        std::set<int> g;
        std::array<int, 8> row_col_di{};
        for (int i=x;i<x+3;i++){
            for (int j=y;j<y+3;j++){
                int n{grid[i][j]};
                if (n>9 || n<1 || !g.insert(n).second) return 0;
                row_col_di[i-x]+=n;
                row_col_di[j-y+3]+=n;
                if ((i - x) == (j - y)) row_col_di[6]+=n;
                if (((i-x)+(j-y))==2) row_col_di[7]+=n;
            }
        }
        if (std::all_of(row_col_di.begin(), row_col_di.end(),[row_col_di](int a){return a==row_col_di[0];})) return 1;
        else return 0;
    }

int numMagicSquaresInside(std::vector<std::vector<int>> grid) {
    int sol{};
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            sol += isMagic(grid, i, j);
        }
    }
    return sol;
}