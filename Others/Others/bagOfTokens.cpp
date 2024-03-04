#include "bagOfTokens.hpp"

int bagOfTokensScore(std::vector<int> tokens, int power) {
    std::sort(tokens.begin(), tokens.end());
    int left{}, right = tokens.size() - 1, cnt{}, score{};
    while (left <= right) {
        if (tokens[left] <= power) {
            power -= tokens[left];
            score++;
            left++;
            cnt++;
        }
        else {
            if (cnt == 0 && right != tokens.size() - 1) {
                break;
            };
            if (score > 0) {
                score--;
                power += tokens[right];
                right--;
                cnt = 0;
            }
            else break;
        }
    }
    if (cnt == 0 && right != tokens.size() - 1) { score++; }
    return score;
}