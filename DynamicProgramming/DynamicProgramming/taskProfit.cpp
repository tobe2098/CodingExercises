#include "taskProfit.hpp"

int jobScheduling(std::vector<int> startTime, std::vector<int> endTime, std::vector<int> profit) {
    //5% speed
    std::vector<Task> tasks;
    for (size_t i = 0; i < startTime.size(); i++) {
        tasks.emplace_back(startTime[i], endTime[i], profit[i]);
    }
    std::sort(tasks.begin(), tasks.end());
    std::vector<Task> stack;
    int max{};
    for (Task& task : tasks) {
        for (auto it = stack.begin(); it != stack.end();) {
            if (it->endTime <= task.startTime) {
                max = std::max(max, it->profit);
                it = stack.erase(it);
            }
            else {
                it++;
            }
        }
        task.profit += max;
        stack.push_back(task);
    }
    // std::unordered_map<int, int> times;
    // int lastTime1{}, lastTime2{};
    // times[lastTime]=0;
    // for (auto&[startTime, endTime, profit]:tasks){
    //     times[startTime]=std::max(times[startTime], times[lastTime]);
    //     lastTime=startTime;
    //     times[endTime]=std::max(times[endTime], times[startTime]+profit);
    // }
    // return times
    max = 0;
    for (const auto& [startTime, endTime, profit] : stack) {
        if (max < profit) max = profit;
    }
    return max;
}

int jobScheduling2(std::vector<int> startTime, std::vector<int> endTime, std::vector<int> profit) {
    //Around 20% speed only
    //dp, at every step, the current is max itself with max the past one, then if start, at end add profit plus current.
    std::unordered_map<int, std::vector<size_t>> map;
    for (size_t i = 0; i < startTime.size(); i++) map[startTime[i]].push_back(i);
    std::unordered_map<int, int> times;
    int lastTime{ (*std::max_element(endTime.begin(), endTime.end())) };
    // std::vector<int> dp(lastTime+1);
    // for (size_t j=0;j<startTime.size();j++){
    //     dp[endTime[j]]=std::max(dp[endTime[j]], dp[i]+profit[j]);
    // }
    startTime.insert(startTime.end(), endTime.begin(), endTime.end());
    std::sort(startTime.begin(), startTime.end());
    int lastTask{};
    for (int i : startTime) {
        // dp[i]=std::max(dp[i], dp[i-1]);
        if (times.count(i) > 0) {
            times[i] = std::max(times[i], times[lastTask]);
            lastTask = i;
        }
        if (map.count(i) > 0) {
            for (size_t index : map[i]) {
                times[endTime[index]] = std::max(times[endTime[index]], times[lastTask] + profit[index]);
            }
        }
    }
    return times[lastTime];
}



namespace job4 {
    using int3 = std::array<int, 3>;
    std::vector<int3> jobs; // (startTime, endTime, profit)
    std::vector<int> dp;
    int n;
    std::vector<int> next;
    void binary_search() {
        for (int i = 0; i < n; i++) {
            // Be careful
            next[i] = upper_bound(jobs.begin() + i, jobs.end(),
                std::array<int, 3>{jobs[i][1], 0, 0}) - jobs.begin();//Binary search for the job that starts after the job i.
            //    cout << i << "->" << next[i] << endl;
        }
    }

    int dfs(int i) {//Recursive fnc
        if (i == n) return 0; //If index==total jobs
        if (dp[i] != -1) return dp[i];//memoization

        // take the job i
        int profit_w_i = jobs[i][2] + dfs(next[i]);

        // Skip the job i
        int profit_n_i = dfs(i + 1);//All job indexes

        // Choose the maximum of profit_w_i & profit_n_i
        return dp[i] = std::max(profit_w_i, profit_n_i);
    }
    int jobScheduling4(std::vector<int> startTime, std::vector<int> endTime, std::vector<int> profit) {
        n = startTime.size();
        job4::jobs.assign(n, { -1, -1, -1 });
        for (int i = 0; i < n; i++)
            job4::jobs[i] = { startTime[i], endTime[i], profit[i] };

        sort(jobs.begin(), jobs.end());
        // Initialize the 'next' vector with the correct size
        next.assign(n, -1);

        dp.assign(n + 1, -1);
        binary_search();
        return dfs(0);
    }
    void iterate() {
        dp.assign(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            // take the job i
            int profit_w_i = jobs[i][2] + dp[next[i]];

            // Skip the job i
            int profit_n_i = dp[i + 1];
            // Choose the maximum of profit_w_i & profit_n_i
            dp[i] = std::max(profit_w_i, profit_n_i);
        }
    }
    int jobScheduling3(std::vector<int> startTime, std::vector<int> endTime, std::vector<int> profit) {
        n = startTime.size();
        jobs.assign(n, { -1, -1, -1 });
        for (int i = 0; i < n; i++)
            jobs[i] = { startTime[i], endTime[i], profit[i] };

        sort(jobs.begin(), jobs.end());
        // Initialize the 'next' vector with the correct size
        next.assign(n, -1);
        binary_search();
        iterate();
        return dp[0];
    }
};
