#pragma once
#include <map>
//CURRENTLY UNOPTIMIZED, LACKS TABULATION AND MAYBE SOME EXTRA CONSIDERATIONS.
unsigned int numRollsToTargetHelper(int k, std::pair<int, int> nntarget, std::map<std::pair<int, int>, int>& hashmap, int mod);
unsigned int numRollsToTarget(int n, int k, int target);