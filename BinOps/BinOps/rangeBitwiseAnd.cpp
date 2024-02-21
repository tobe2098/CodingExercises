#include "rangeBitwiseAnd.hpp"

int rangeBitwiseAndBest(int left, int right) {
    int t = 0;
    while (left < right) {
        left >>= 1;
        right >>= 1;
        ++t;
    }
    return left << t;
}

int rangeBitwiseAndMine(int left, int right) {
    int res{};
    for (int i = 31; i >= 0; i--) {
        int first1{ (left >> i) & 1 }, second1{ (right >> i) & 1 };
        if (first1 & second1) {
            res |= (1) << i;
        }
        else if (first1 || second1) {
            break;
        }
    }
    return res;
}
