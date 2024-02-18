#include "roomBook.hpp"

bool comp(std::vector<int>& v1, std::vector<int>& v2) {
    return v1[0] < v2[0];
}

int mostBooked(int n, std::vector<std::vector<int>> meetings) {
    std::sort(meetings.begin(), meetings.end(), &comp);
    std::vector<std::pair<int, int>> rooms_MnEnd(n, { 0,0 });
    for (std::vector<int>& meet : meetings) {
        bool flag = false;
        int mindiff{INT_MIN}, minidx{}, idx{};
        for (auto& [count, endTime] : rooms_MnEnd) {
            int diff{ meet[0] - endTime };
            if (diff >= 0) {
                count++;
                flag = true;
                endTime = meet[1];
                break;
            }
            else {
                if (diff > mindiff) {
                    mindiff = diff;
                    minidx = idx;
                }
            }
            idx++;
        }
        if (!flag) {
            rooms_MnEnd[minidx].first++;
            rooms_MnEnd[minidx].second = meet[1] - mindiff;
        }
    }
    int idx{}, max{};
    for (int i = 0; i < rooms_MnEnd.size(); i++) {
        if (rooms_MnEnd[i].first > max) {
            idx = i;
            max = rooms_MnEnd[i].first;
        }
    }
    return idx;
}