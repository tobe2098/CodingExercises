#include "GetPermutations.hpp"

namespace getPerm {
    void getNextPermutation(int ptr, std::string& sol, std::string& curr) {
        if (ptr == m - 1) {
            count--;
            if (count == 0) sol = curr;
            return;
        }
        if (count <=0) {
            return;
        }
        getNextPermutation(ptr + 1, sol, curr);
        for (int ptr2 = ptr + 1; ptr2 < curr.size(); ptr2++) {
            for (int i = ptr2; i > ptr; i--) {
                std::swap(curr[i], curr[i-1]);
            }
            getNextPermutation(ptr + 1, sol, curr);
            for (int i = ptr; i < ptr2; i++) {
                std::swap(curr[i], curr[i + 1]);
            }
        }
    }

    std::string getPermutation(int n, int k) {
        std::string curr, sol;
        for (int i = 0; i < n; i++) {
            curr.push_back(i + '1');
        }
        m = n;
        count = k;
        getNextPermutation(0, sol, curr);
        //There was a problem where we did this, but I could not solve it on my own. There is an inbuilt function for the next lexicographic permutation too. The solution has to do with doing swaps in limited ranges in recursive calls.
        return sol;
    }
    std::string getPermutationFast(int n, int k) {
        int fact = 1; std::vector<int> x;
        for (int i = 1; i < n; i++) {
            fact *= i;
            x.push_back(i);
        }
        x.push_back(n);
        std::string ans = "";
        k--;
        while (true) {
            ans = ans + std::to_string(x[k / fact]);
            x.erase(x.begin() + k / fact);
            if (x.size() == 0) break;
             k = k % fact;
            fact /= x.size();
        }
        return ans;
    }
}

