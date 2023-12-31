#include "noDieRollsTarget.hpp"

unsigned int numRollsToTargetHelper(int k, std::pair<int, int> nntarget, std::map<std::pair<int, int>, int>& hashmap, int mod) {
    if (nntarget.second < 0 || nntarget.first < 0 || (nntarget.second == 0 && nntarget.first > 0)) return 0;
    else if (nntarget.second == 0) return 1;
    else if (hashmap.count(nntarget) > 0) return hashmap[nntarget];
    int count{};
    for (int i = 1; i <= k; i++) {
        count += numRollsToTargetHelper(k, { nntarget.first - 1, nntarget.second - i }, hashmap, mod);
        count %= mod;
    }
    hashmap[nntarget] = count;
    return hashmap[nntarget];
}
unsigned int numRollsToTarget(int n, int k, int target) {
    std::map<std::pair<int, int>, int> hashmap;
    int mod = static_cast<int>(pow(10, 9) + 7);
    return (numRollsToTargetHelper(k, { n,target }, hashmap, mod) % 1000000007);
}