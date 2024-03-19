#include "leastInterval.hpp"

int leastInterval(std::vector<char> tasks, int n) {
        std::array<int,26>freq{ };
        for (char task : tasks)freq[task - 'A']++;
        std::sort(begin(freq), end(freq));
        int chunk = freq[25] - 1;
        int idel = chunk * n;

        for (int i = 24; i >= 0; i--) {
            idel -= std::min(chunk, freq[i]);
        }

        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
