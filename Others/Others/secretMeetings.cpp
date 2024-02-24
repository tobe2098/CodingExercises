#include "secretMeetings.hpp"

std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
    //First approach, does not work
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

std::vector<int> findAllPeople2(int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
    //Works
    std::sort(meetings.begin(), meetings.end(), [](std::vector<int>& a, std::vector<int>& b) {return a[2] < b[2]; });
    std::vector<SGraphNode> graph;
    for (int i = 0; i < n; i++) graph.emplace_back(i);
    int maxTime{};
    for (std::vector<int>& meet : meetings) {
        graph[meet[0]].meets_time[meet[2]].push_back(meet[1]);
        graph[meet[1]].meets_time[meet[2]].push_back(meet[0]);
        if (maxTime < meet[2]) maxTime = meet[2];
    }
    std::vector<SGraphNode*> know;
    know.push_back(&graph[0]);
    know.push_back(&graph[firstPerson]);
    std::set<int> sol{ 0,firstPerson };
    for (int time = 0; time <= maxTime; time++) {
        for (int i = 0; i < know.size(); i++) {
            if (know[i]->meets_time.contains(time)) {
                for (int num : know[i]->meets_time[time]) {
                    if (!sol.contains(num)) {

                        know.push_back(&graph[num]);
                        sol.insert(num);
                    }
                };
            }
        }
        if (know.size() == n) break;
    }
    return std::vector<int>(sol.begin(), sol.end());
}