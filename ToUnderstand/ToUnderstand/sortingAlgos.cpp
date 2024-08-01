#include "sortingAlgos.hpp"


std::vector<int> mergeSortInPlace(std::vector<int> nums){
    mergeSort(nums, 0, nums.size());
    return nums;
}

std::vector<int> mergeSortWithONspace(std::vector<int> nums){
    std::vector<int> temp(nums.size());
    mergeSort2(nums, 0, nums.size(), temp);
    return nums;
}

std::vector<int> bottomUpMergeSort(std::vector<int> nums){
    int n = nums.size();
    std::vector<int> temp(n);
    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left + size < n; left += 2 * size) {
            int mid{ std::min(left + size,n) };
            int right{ std::min(left + 2 * size,n) };
            merge(nums, left, mid, right, temp);
        }
    }
    return nums;
}

void mergeSort(std::vector<int>& nums, int start, int end) {
    //Works, but it is very inefficient
    if (end- start<= 1) return;
    int mid{ (start + (end - start) / 2)};
    mergeSort(nums, start, mid );
    mergeSort(nums, mid, end);
    int p1{ start }, p2{ mid };
    while (p1 < p2 && p2 < end) {
        if (nums[p1] > nums[p2]) {
            int plc{ nums[p2] };
            for (int k = p1; k <= p2; k++) {
                std::swap(plc, nums[k]);
            }
            p2++;
            p1++;
        }
        else p1++;
    }
}

void mergeSort2(std::vector<int>& nums, int start, int end, std::vector<int>& temp){
    if (end - start <= 1) return;
    int mid{ (start + (end - start) / 2) };
    mergeSort2(nums, start, mid,temp);
    mergeSort2(nums, mid, end,temp);
    merge(nums, start, mid, end,temp);
}

void merge(std::vector<int>& nums, int left, int mid, int right, std::vector<int>& temp) {
    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        }
        else {
            temp[k++] = nums[j++];
        }
    }

    while (i < mid) {
        temp[k++] = nums[i++];
    }

    while (j < right) {
        temp[k++] = nums[j++];
    }

    for (int i = left; i < right; ++i) {
        nums[i] = temp[i];
    }
}

void radix(std::vector<int>& nums, int bits, int min_num, int mask, int shifts, std::vector <std::vector< int >>& buckets){
    // if (__popcnt(mask)!=bits) throw;
    for (int n : nums) {
        buckets[(n + min_num & mask) >> (bits * shifts)].push_back(n);
    }
    int i{};
    for (std::vector<int>& b : buckets) {
        for (int n : b) {
            nums[i++] = n;
        }
        b.clear();
    }
}

std::vector<int> radixSortFixed(std::vector<int> nums){
    int bits{ 6 };
    std::vector <std::vector< int >>buckets(2 << (bits-1));
    int mask{ (1 << 6) - 1 };
    for (int i = 0; i < 3; i++, mask <<= 6) {
        radix(nums, bits, 5e4, mask,i, buckets);
    }   
    return nums;
}

std::vector<int> radixSortAll(std::vector<int> nums){
    std::vector<int> negs, pos;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < 0) negs.push_back(nums[i]);
        else pos.push_back(nums[i]);
    }
    std::array<std::vector<int>, 2> buckets{};
    int mask{ 1 };
    for (int i = 0; i < 31; i++, mask <<= 1) {
        for (int n : pos) {
            buckets[(n & mask) >> i].push_back(n);
        }
        int j{};
        for (std::vector<int>& b : buckets) {
            for (int n : b) {
                pos[j++] = n;
            }
            b.clear();
        }
        for (int n : negs) {
            buckets[(n & mask) >> i].push_back(n);
        }
        j = 0;
        for (std::vector<int>& b : buckets) {
            for (int n : b) {
                negs[j++] = n;
            }
            b.clear();
        }
    }
    //negs.append_range(pos);
    negs.insert(negs.end(), pos.begin(), pos.end());
    return negs;
}

