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
void rec(std::vector<int>& sol, std::string& expression, std::unordered_map<std::string, int>& map, int opcount) {
    if (map.count(expression) > 0) return;
    if (opcount == 0) {
        sol.push_back(std::stoi(expression));
        return;
    }
    std::string num1, num2, cons, rep;
    char op{};
    for (int i = 0; i < expression.size(); i++) {
        if (num2.empty() || expression[i] != '+' && expression[i] != '-' && expression[i] != '*') {
            num2.push_back(expression[i]);
            continue;
        }
        if (num1.empty()) {
            cons.append(num2);
            cons.push_back(expression[i]);
            op = expression[i];
            num1.swap(num2);
            continue;
        }
        int res{ oper(std::stoi(num1),std::stoi(num2),op) };
        rep.append(std::to_string(res));
        for (int j = i; j < expression.size(); j++) rep.push_back(expression[j]);
        rec(sol, rep, map, opcount - 1);
        rep = cons;
        num1 = num2;
        num2.clear();
        op = expression[i];
        cons.append(num1);
        cons.push_back(expression[i]);
    }
    int res{ oper(std::stoi(num1),std::stoi(num2),op) };
    rep.append(std::to_string(res));
    rec(sol, rep, map, opcount - 1);
    map[expression]++;
}

std::vector<int> diffWaysToCompute(std::string expression) {
    int opcount{};
    for (char c : expression) opcount += (c == '+' || c == '-' || c == '*');
    std::vector<int> sol;
    std::unordered_map<std::string, int> map;
    rec(sol, expression, map, opcount);
    return sol;
}