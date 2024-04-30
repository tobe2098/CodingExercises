#include "prefixSum.hpp"

long long wonderfulSubstrings(std::string word) {
    long long sol{};
    std::unordered_map<int, std::array<int, ('j' - 'a') + 1>>prefix_sum;
    std::array<int, ('j' - 'a') + 1> oddeven{};
    prefix_sum[-1] = oddeven;
    for (int i = 0; i < word.length(); i++) {
        oddeven[word[i] - 'a'] ^= 1;
        prefix_sum[i] = oddeven;
    }
    for (int i = 0; i < word.length(); i++) {
        for (int j = i + 1; j < word.length(); j++) {
            int odds{};
            for (int k = 0; k < 10; k++) odds += (prefix_sum[i-1][k] ^ prefix_sum[j][k]);
            if (odds <= 1) sol++;
        }
    }


    //No odds
    // int odds{};
    // for (int i=0;i<10;i++) odds+=prefix_sum[index1][i]^prefix_sum[index2][i];

    return sol;
}