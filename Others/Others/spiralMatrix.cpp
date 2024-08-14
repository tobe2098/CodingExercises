#include "spiralMatrix.hpp"

std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    int total{ rows * cols };
    std::vector<std::vector<int>> sol(total);
    sol[0] = { rStart,cStart };
    int dist{ 1 }, dir{}, trans{ 0 }, runs{ 0 }, index{ 1 }, i{ rStart }, j{ cStart };
    while (index < total) {
        auto& [ip, ij] = spiral[dir];
        i += ip;
        j += ij;
        trans++;
        if (trans == dist) {
            trans = 0;
            runs++;
            dir = (dir + 1) % 4;
            if (runs == 2) {
                runs = 0;
                dist++;
            }
        }
        if (i < rows && i >= 0 && j < cols && j >= 0) {
            sol[index++] = { i,j };
        }
    }
    return sol;
}