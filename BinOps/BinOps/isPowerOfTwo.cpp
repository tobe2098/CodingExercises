#include "isPowerOfTwo.hpp"

bool isPowerOfTwo(int n) {
    return (n > 0 && !(n & (n - 1))); //Way more elegant
}

bool isPowerOfTwoPopCount(int n){
    return n>0&&(_mm_popcnt_u64(n)==1);//__builtin_popcount() in GCC
    //return n > 0 && (__builtin_popcount(n) == 1);
}
