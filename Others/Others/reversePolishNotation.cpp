#include "reversePolishNotation.hpp"

int execOp(int num1, int num2, std::string& op) {
    if (op == "+") {
        return num1 + num2;
    }
    else if (op == "-") {
        return num1 - num2;
    }
    else if (op == "*") {
        return num1 * num2;
    }
    else {
        return num1 / num2;
    }
}

int evalRPN(std::vector<std::string> tokens) {
    std::vector<int> stack;
    for (std::string& s : tokens) {
        if (s[s.length() - 1] <= 47) {
            int num1{ stack.back() };
            stack.pop_back();
            int num2{ stack.back() };
            stack.pop_back();
            stack.push_back(execOp(num2, num1, s));
        }
        else {
            stack.push_back(std::stoi(s));
        }
    }
    return stack.back();
}