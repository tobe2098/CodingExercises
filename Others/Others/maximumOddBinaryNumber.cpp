#include "maximumOddBinaryNumber.hpp"

bool compChar(char a, char b) {
    return a > b;

}

std::string maximumOddBinaryNumber(std::string s) {
    std::sort(s.begin(), s.end(), compChar);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '0') {
            std::swap(s[i - 1], s[len - 1]);
            break;
        }
    }
    return s;
}