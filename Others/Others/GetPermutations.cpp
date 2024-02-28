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
        /*Take n=3 as an example.
There are 3! permuatation which are [123,132,213,231,312,321].
As we can see there are 2 permutations start with "1".
There are also 2 permutations start with "2" and start with "2".

We can look at the n-permuation formula to get some insight:
The formula means we have n possibilities to choose 1st element. And if this is chosen, we still need to permutate remaining (n-1) elements; there are (n-1)! possiblities of permutatation of (n-1) elements.

In other word, there are (n-1)! permutations start with 1, with 2, with 3 etc.*/
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

