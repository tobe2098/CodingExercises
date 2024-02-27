#pragma once
#include <string>
#include <vector>

namespace getPerm {
    static int m{}, count{};
    void getNextPermutation(int ptr, std::string& sol, std::string& curr);
    std::string getPermutation(int n, int k);
    std::string getPermutationFast(int n, int k);
}

