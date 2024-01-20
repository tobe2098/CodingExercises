#include "sumSubarrayMin.hpp"

int sumSubarrayMins(std::vector<int> arr) {
    size_t size{ arr.size() };
    std::vector<int> dp(size, 0);
    int res{ arr[0] };
    // while(minidx<size){
    //     for (size_t i=minidx;i<size;i++){
    //         if (arr[i]<minidx) minidx=i;
    //     }
    // }
    dp[0] = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            dp[i] = arr[i] * (i + 1);
        }
        else {
            arr[i] = arr[i - 1];
            dp[i] = arr[i] + dp[i - 1];
        }
        res += dp[i];
        res %= (static_cast<int>(1e9) + 7);
    }
    // for (size_t i=0;i<size;i++){
    //     for (size_t j=i;j<size;j++){
    //         if (arr[i]<arr[j]) res+=arr[i];
    //         else {
    //             arr[i]=arr[j];
    //             res+=arr[i];
    //         }
    //     }
    //     res%=(static_cast<int>(1e9) + 7);
    // }
    return res;
}
