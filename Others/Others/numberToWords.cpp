#include "numberToWords.hpp"

std::string numberToWords(int num) {
    static std::unordered_map<int, std::string> dict{ {0,""},{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"},{20,"Twenty"},{30,"Thirty"},{40,"Forty"},{50,"Fifty"},{60,"Sixty"},{70,"Seventy"},{80,"Eighty"},{90,"Ninety"},{100, "Hundred"}, {1000, "Thousand"}, {1000, "Thousand"}, {1000000, "Million"}, {1000000000, "Billion"} };
    std::vector<std::string> stack;
    int n{ num }, p{ 1 };
    for (int i = 0; i < 3 && n>0; i++) {
        auto [q, r] = div(n, 100);
        if (dict.count(r) > 0) stack.push_back(dict[r]);
        else {
            auto [q3, r3] = div(r, 10);
            stack.push_back(dict[r3]);
            stack.push_back(dict[q3 * 10]);
        }
        auto [q2, r2] = div(q, 10);
        if (r2) {
            stack.push_back(dict[100]);
            stack.push_back(dict[r2]);
        }
        n = q2;
        p *= 1000;
        if (n)stack.push_back(dict[p]);
    }
    if (n) stack.push_back(dict[n]);
    std::string sol;
    for (int i = stack.size() - 1; i >= 0; i--) {
        sol += stack[i];
        sol += " ";
    }
    sol.pop_back();
    return sol;
}