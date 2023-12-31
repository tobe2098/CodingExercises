#ifndef JOBDIFFICULTY
#define JOBDIFFICULTY
#include <vector>
#include <map>
#include <algorithm>

int minDifficultyTab(std::vector<int> jobDifficulty, int d);
int minDifficultyTab2(std::vector<int> jobDifficulty, int d);
int minDifficultyHelper(std::vector<int> jobDifficulty, int d, std::map<int, int>& hashmap);
int minDifficulty(std::vector<int> jobDifficulty, int d);

#endif