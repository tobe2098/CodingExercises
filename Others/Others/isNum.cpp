#include "isNum.hpp"

bool isNumber(std::string s) {
    int ptr{}, size = s.length();
    bool num{ false }, Enum{ true };
    if (s[ptr] == '+' || s[ptr] == '-') {
        ptr++;
    }
    while ((s[ptr] >= '0' && s[ptr] <= '9') && ptr < size) {
        ptr++;
        num = true;
    }
    if (s[ptr] == '.' && ptr < size) ptr++;
    while ((s[ptr] >= '0' && s[ptr] <= '9') && ptr < size) ptr++, num = true;
    if ((s[ptr] == 'e' || s[ptr] == 'E') && ptr < size) ptr++, Enum = false;
    if (s[ptr] == '+' || s[ptr] == '-') {
        ptr++;
        if (Enum) return false;
    }
    while ((s[ptr] >= '0' && s[ptr] <= '9') && ptr < size) ptr++, Enum = true;
    return (ptr == size) && num && Enum;
}

bool isNumber2(std::string s) {

    int i = 0;
    int n = s.size() - 1;
    if (s[n] == 'e' || s[0] == 'e') return false;
    if (s[i] == '+' || s[i] == '-') i++;
    int e = 0, d = 0;

    bool z = false;

    while (i < s.size()) {

        if (s[i] <= '9' && s[i] >= '0') { i++; z = true; }
        else if (s[i] == '.') { if (d != 0 || e != 0 || s.size() == 1) { return false; } d = 1; i++; }
        else if (s[i] == 'e' || s[i] == 'E') { if (e != 0 || !z || i == n) { return false; } e = 1; i++; }
        else if (s[i] == '+' || s[i] == '-') { if (i == 0 || (s[i - 1] != 'e' && s[i - 1] != 'E') || i == n) { return false; }i++; }
        else { return false; }


    }
    if (!z) return false;
    return true;
}
