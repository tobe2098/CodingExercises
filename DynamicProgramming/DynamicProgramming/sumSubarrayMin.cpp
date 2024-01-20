#include "sumSubarrayMin.hpp"

int sumSubarrayMins(std::vector<int> arr) {
    size_t size{ arr.size() };
    std::vector<int> monotonic_stack(1); //Monotonic stack of indices
    std::vector<int> acc(size); //Monotonic stack of indices
    int res{ arr[0] };
    // while(minidx<size){
    //     for (size_t i=minidx;i<size;i++){
    //         if (arr[i]<minidx) minidx=i;
    //     }
    // }
    acc[0] = arr[0];
    for (size_t i = 1; i < size; i++) {
        while (!monotonic_stack.empty() && arr[i] < arr[monotonic_stack.back()]) {
            monotonic_stack.pop_back();
        }
        
        if (monotonic_stack.empty()) {
            acc[i] = (arr[i] * (i + 1));
            res += acc[i];
            res %= (static_cast<int>(1e9) + 7);
        }
        else {
            acc[i] = (arr[i] * (i - monotonic_stack.back()) + acc[monotonic_stack.back()]);
            res += acc[i];
            res %= (static_cast<int>(1e9) + 7);
        }

        monotonic_stack.push_back(i);
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
