#include "parenthesis.hpp"

int oper(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else {
        return a * b;
    }
}
std::vector<int> rec(std::vector<int> res, std::string expression) {
    if (expression.size() == 0) return res;
    if (expression.size()<3){
        res.push_back(std::stoi(expression));
        return res;
    }
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] != '+' && expression[i] != '*' && expression[i] != '-') continue;
        char op{ expression[i] };
        std::vector<int> left{ rec({},expression.substr(0,i)) }, right{ rec({}, expression.substr(i + 1,expression.size() - i)) };
        for (int l : left) for (int r : right) {
            res.push_back(oper(l, r, op));
        }


    }
    return res;
}

std::vector<int> rec2(std::string& expression, std::vector<std::vector<std::vector<int>>>& memo, int begin, int end) {
    if (begin == end) {
        return { expression[begin] - '0' };
    }
    if (end - begin < 2) {
        return { (expression[begin] - '0') * 10 + expression[end] - '0' };
    }
    if (!memo[begin][end].empty()) return memo[begin][end];
    for (int i = begin; i <= end; i++) {
        if (isdigit(expression[i])) continue;
        char oper{ expression[i] };
        std::vector<int> left{ rec2(expression, memo, begin, i - 1) }, right{ rec2(expression, memo, i + 1, end) };
        for (int l : left) for (int r : right) memo[begin][end].push_back(oper(l, r, oper));
    }
    return memo[begin][end];
}
 std::vector<int> diffWaysToComputeRec(std::string expression) {
     return rec({},expression);
}

 std::vector<int> diffWaysToComputeMemo(std::string expression)
 {
     std::vector<std::vector<std::vector<int>>> memo(expression.size(), std::vector<std::vector<int>>(expression.size()));
     return rec2(expression, memo, 0, expression.size()-1);
 }

 std::vector<int> diffWaysToComputeTab(std::string expression) {
     //Resolve with tabular 2D
     std::vector<std::vector<std::vector<int>>> dp(expression.size(), std::vector<std::vector<int>>(expression.size(), std::vector<int>()));
     for (int i = 0; i < expression.size(); i++) {
         if (!isdigit(expression[i])) continue;
         if (i + 1 < expression.size() && isdigit(expression[i + 1])) {
             dp[i][i + 1].push_back((expression[i] - '0') * 10 + (expression[i + 1] - '0'));
         }
         else {
             dp[i][i].push_back((expression[i] - '0'));
         }
     }
     for (int len = 3; len <= expression.size(); len++) for (int start = 0; start + len <= expression.size(); start++) {
         for (int split = start + 1; split < start + len - 1; split++) {
             if (isdigit(expression[split])) continue;
             std::vector<int>& left{ dp[start][split - 1] }, & right{ dp[split + 1][start + len - 1] };
             // for (int l:left) for (int r:right) dp[0][0].push_back(op(l,r,expression[split]));
             for (int l : left) for (int r : right) dp[start][start + len - 1].push_back(oper(l, r, expression[split]));
         }
     }
     // return dp.front().front();
     return dp.front().back();
 }