#include "possiblePaths.hpp"

long long possiblePathsTab(int rows, int columns) {
    if (rows <= 0 || columns <= 0) return 0;
    std::vector<std::vector<long long>> grid(rows, std::vector<long long>(columns, 0));
    //Make the table bigger, put the 1 in [1][1] instead (if possible) and then do the thing and return last [i][j] for solution of video
    grid[0][0] = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            //if (j == 0 && i == 0) continue;
            grid[i][j] = ((i - 1 >= 0) ? grid[i - 1][j] : 0) + ((j - 1 >= 0) ? grid[i][j - 1] : 0);
        }
    }
    return grid[rows - 1][columns - 1];
}
//Recursive version is calling with reduced rows or columns depending on the movement until you  reach the base case and walk it back adding the number of ways