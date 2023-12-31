#include "jobDifficulty.hpp"

int minDifficultyTab(std::vector<int> jobDifficulty, int d) {
    //My version, does not work. Logic is too complicated!
    if (jobDifficulty.size() < d) {
        return -1;
    }
    else if (jobDifficulty.size() == d) {
        int totalDifficulty = 0;
        for (int difficulty : jobDifficulty)
            totalDifficulty += difficulty;
        return totalDifficulty;
    }
    //else if (d == 1) return *std::max_element(jobDifficulty.begin(), jobDifficulty.end());
    std::vector <std::vector< int >> dp(jobDifficulty.size()+1, std::vector<int>(d+1, -1));
    dp[0][0] = 0;
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 1; j <= i && j<=d; j++) {
            int prevColMin{ dp[i-1][j - 1] };
            if (prevColMin != -1) {
                dp[i][j] =prevColMin + jobDifficulty[i - 1]; //New group with current task as the only number
                for (int k = i - 2; k >= 0; k--) {
                    if (dp[k][j - 1] != -1 && dp[k][j - 1] <= prevColMin) {
                        prevColMin = dp[k][j - 1];
                    }
                    else break;
                }
                int colMax{ dp[i - 1][j] };
                bool found{ false };
                for (int k = i - 2; k >= 0; k--) {
                    if (dp[k][j] != -1 && dp[k][j] >= colMax) {
                        colMax = dp[k][j ];
                        found = true;
                    }
                    else {
                        if (found) break;
                        else {
                        colMax = INT_MAX;
                        break;
                        }
                    }
                }
                //Here we have localColMin if there is one. If there is there has to be a i-1 j-1 non-1 element. It represents the lack 
                if (dp[i - 1][j] != -1) {
                    dp[i][j] = std::min(std::min(std::max(prevColMin + jobDifficulty[i - 1], dp[i - 1][j]), dp[i][j]), colMax);//New number is now part of an old group
                    //So the max between previous difficulty of that group and the difficulty of the other gruops and the diff of current task
                }
                else {
                    dp[i][j] = std::min(prevColMin + jobDifficulty[i - 1], dp[i][j]);
                }
            }
            else if (dp[i - 1][j] != -1) {
                dp[i][j] = std::max(jobDifficulty[i - 1], dp[i - 1][j]);//New number is now part of an old group
            }

            

        }
    }
    return dp.back().back();
}

int minDifficultyTab2(std::vector<int> jobDifficulty, int d) {
    //I tried making it on my own, failed. Still do not completely understand
    if (jobDifficulty.size() < d) {
        return -1;
    }
    else if (jobDifficulty.size() == d) {
        int totalDifficulty = 0;
        for (int difficulty : jobDifficulty)
            totalDifficulty += difficulty;
        return totalDifficulty;
    }
    //else if (d == 1) return *std::max_element(jobDifficulty.begin(), jobDifficulty.end());
    std::vector <std::vector< int >> dp(jobDifficulty.size(), std::vector<int>(d, -1));
    dp[0][0] = jobDifficulty[0];
    for (int i = 1; i < dp.size(); i++) dp[i][0] = std::max(dp[i - 1][0], jobDifficulty[i]);
    for (int i = 0; i < dp.size(); i++) {//You can do it with two vectors and one swap instead of matrix (invert for loops)
        for (int j = 1; j <= i && j < d; j++) {//This only stops from going beyond possible cases in one direction, not the following loop
            int maxJobLastGroup{ jobDifficulty[i] };
            int tempMin{ dp[i - 1][j-1] + maxJobLastGroup };
            for (int k = i - 1; k >= j; k--) {//This is to stop in the diagonal (and avoid impossible cases)
                maxJobLastGroup = std::max(maxJobLastGroup, jobDifficulty[k]);
                tempMin = std::min(tempMin, dp[k - 1][j - 1]+maxJobLastGroup);
            }
            dp[i][j] = tempMin;
        }
    }
    return dp.back().back();
}

int minDifficultyHelper(std::vector<int> jobDifficulty, int d, std::map<int, int>& hashmap) {
    //Works but it is too slow
    if (jobDifficulty.size() < d || d == 0 || jobDifficulty.empty()) return -1;
    else if (d == 1) return *std::max_element(jobDifficulty.begin(), jobDifficulty.end());
    else if (hashmap.count(jobDifficulty.size()) > 0) return hashmap[jobDifficulty.size()];
    int cutMax{}, out{}, sol{ 0 };
    while (jobDifficulty.size()>=d) {
        cutMax = std::max(jobDifficulty.back(), cutMax);
        jobDifficulty.pop_back();
        out = minDifficultyHelper(jobDifficulty, d - 1, hashmap);
        if (out != -1 && (sol > out+cutMax || sol == 0)) {
            sol = out+cutMax;
        }
    }
    hashmap[jobDifficulty.size()] = sol;
    return hashmap[jobDifficulty.size()];
}

int minDifficulty(std::vector<int> jobDifficulty, int d) {
    if (jobDifficulty.size() < d || d == 0) return -1;
    std::reverse(jobDifficulty.begin(), jobDifficulty.end());
    std::map<int, int> hashmap;

    return minDifficultyHelper(jobDifficulty, d, hashmap);
}
