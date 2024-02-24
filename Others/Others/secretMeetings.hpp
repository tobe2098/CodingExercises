#pragma once
#include <vector>
#include <set>
#include <algorithm>
std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
    std::set<int> sol{ 0,firstPerson };
    std::sort(meetings.begin(), meetings.end(), [](std::vector<int>& a, std::vector<int>& b) {
        return a[2] < b[2];
        });
    int currtime{};
    std::vector<int> temp;
    for (int index = 0; index < meetings.size(); index++) {
        if (currtime == meetings[index].back()) {
            temp.push_back(meetings[index][0]);
            temp.push_back(meetings[index][1]);
        }
        else {
            for (int num : temp) {
                if (sol.contains(num)) {
                    sol.insert(temp.begin(), temp.end());
                }
            }
            temp.clear();
            currtime = meetings[index].back();
            temp.push_back(meetings[index][0]);
            temp.push_back(meetings[index][1]);
        }
    }
    for (int num : temp) {
        if (sol.contains(num)) {
            sol.insert(temp.begin(), temp.end());
        }
    }
    return std::vector<int>(sol.begin(), sol.end());
}