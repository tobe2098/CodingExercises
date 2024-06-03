#pragma once
#include <vector>

void reverseString(std::vector<char> s) {
    size_t left{}, right = s.size()-1;
    while (left < right) {
        std::swap(s[left], s[right]);
        left++;
        right--;
    }
}