#include "roomBook.hpp"

bool comp(std::vector<int>& v1, std::vector<int>& v2) {
    return v1[0] < v2[0];
}

int mostBooked(int n, std::vector<std::vector<int>> meetings) {
    std::sort(meetings.begin(), meetings.end());
    std::vector<std::pair<int, long long>> rooms_MnEnd(n, { 0,0 });
    for (std::vector<int>& meet : meetings) {
        bool flag = false;
        long long val{ LONG_MAX };
        int minidx{ -1 }, idx{};
        // for (int j=0;j<n;j++){ Alt loop
        //     if (rooms_MnEnd[j].second<val){
        //         val=rooms_MnEnd[j].second;
        //         minidx=j;
        //     }
        //     if (meet[0]>=rooms_MnEnd[j].second){
        //         flag=true;
        //         rooms_MnEnd[j].first++;
        //         rooms_MnEnd[j].second=meet[1];
        //         break;
        //     }
        // }
        for (auto& [count, endTime] : rooms_MnEnd) {
            if (endTime < val) {
                val = endTime;
                minidx = idx;
            }
            if (meet[0] >= endTime) {
                count++;
                flag = true;
                endTime = meet[1];
                break;
            }


            idx++;
        }
        if (!flag) {
            rooms_MnEnd[minidx].first++;
            rooms_MnEnd[minidx].second += static_cast<long long>(meet[1] - meet[0]);
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