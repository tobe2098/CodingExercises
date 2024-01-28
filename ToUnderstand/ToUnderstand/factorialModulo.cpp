#include "factorialModulo.hpp"

int factmod(int n, int p) {
    std::vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p; i++)
        f[i] = f[i - 1] * i % p;

    int res = 1;
    while (n > 1) {
        if ((n / p) % 2)
            res = p - res;
        res = res * f[n % p] % p;
        n /= p;
    }
    return res;
}

int noTwosInFactorial(int num) {
    //This works because when you do num/2, you get all the times you find 2**1 in the numbers between 1 and num.
    //This expands for the rest of powers of 2, which gets you the number of 2s by summing like that.
    int res{}, p{ 1 };
    for (int i : std::ranges::iota_view{ 1,num }) {
        if (p > num) break;
        p *= 2;
        res *= num / p;
    }
    return res;
}
