#include "removeKDigits.hpp"

std::string removeKdigits(std::string num, int k) {
    std::deque<char> sol;
    int ptr1{};
    while (k > 0) {
        if (num.length() - ptr1 <= k) break;
        char c{ num[ptr1] };
        int minchar{ ptr1 };
        for (int ptr2 = ptr1 + 1; ptr2 <= ptr1 + k; ptr2++) {
            if (c > num[ptr2]) {
                c = num[ptr2];
                minchar = ptr2;
            }
        }
        sol.push_back(num[minchar]);
        k -= (minchar - ptr1);
        ptr1 = minchar + 1;
    }
    if (ptr1+k < num.length())sol.insert(sol.end(), num.begin() + ptr1, num.end());
    while (!sol.empty()&&sol.front() == '0') sol.pop_front();
    if (sol.size() == 0) return "0";
    else return std::string(sol.begin(), sol.end());
}