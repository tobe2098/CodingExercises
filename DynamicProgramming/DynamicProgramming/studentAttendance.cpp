#include "studentAttendance.hpp"
int checkRecord(int n) {
    //Use pairs to keep track of the non-A combinations and the A-combs (should be combs*length, so no)?
    //Total merged is left*right of non-A with special attention to restrict the LL-LL,
    //Plus right-A times non-A left(following the exact same constrants, so same number),
    //Plus left-A times non-A right.
    //How do I calculate the non-As in a record of length n? Do it from the base case (2 or 1)
    std::pair<std::array<unsigned long long, 3>, std::array<unsigned long long, 3>> dp{ {1,0,0},{1,1,0} };
    for (int i = 1; i < n; i++) {
        std::pair<std::array<unsigned long long, 3>, std::array<unsigned long long, 3>> newdp{};
        newdp.first[0] = (dp.first[0] + dp.first[1] + dp.first[2] + dp.second[0] + dp.second[1] + dp.second[2]) % mod;
        newdp.first[1] = dp.first[0];
        newdp.first[2] = dp.first[1];
        newdp.second[0] = (dp.second[0] + dp.second[1] + dp.second[2]) % mod;
        newdp.second[1] = dp.second[0];
        newdp.second[2] = dp.second[1];
        std::swap(dp, newdp);
    }
    return (dp.first[0] + dp.first[1] + dp.first[2] + dp.second[0] + dp.second[1] + dp.second[2]) % mod;
}