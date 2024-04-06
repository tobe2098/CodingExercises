#include "stringManipulation.hpp"

std::string minRemoveToMakeValid(std::string s) {
    int depth{};
    for (auto it = s.begin(); it != s.end();) {
        if (*it == '(') {
            depth++;
        }
        else if (*it == ')') {
            depth--;
        }
        if (depth < 0) {
            it = s.erase(it);
            depth++;
        }
        else {
            it++;
        }
    }
    auto it = s.end()-1;
    while (depth > 0) {
        if (*it == '(') {
            it = s.erase(it);
            it--;
            depth--;
        }
        else it--;
    }
    return s;
}