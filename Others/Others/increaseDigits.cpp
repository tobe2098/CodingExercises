#include "increaseDigits.hpp"

std::vector<int> plusOne(std::vector<int> digits) {
    int ptr = digits.size() - 1;
    while (ptr >= 0&&digits[ptr] == 9 ) {
        digits[ptr] = 0;
        ptr--;
    }
    if (ptr == -1) {
        digits.insert(digits.begin(), 1);
    }
    else digits[ptr]++;
    return digits;
}