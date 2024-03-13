#include "pivotInteger.hpp"

int pivotInteger(int n) {
    int second{};
    for (int i = 1; i <= n; i++)second += i;
    int first{ 1 }, num{ 1 };
    while (first < second) {
        num++;
        first += num;
        second -= num-1;
    }
    if (first == second) return num;
    else return -1;
}
