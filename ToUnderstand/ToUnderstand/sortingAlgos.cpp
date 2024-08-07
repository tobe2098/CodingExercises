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

std::vector<int> quickSortWrapper(std::vector<int> nums){
    quicksortInPlace(nums, 0, nums.size()-1);
    return nums;
}

void quicksortInPlace(std::vector<int>& nums, int start, int end) {
    if (end - start <= 0) return;
    int mid{ start + (end - start) / 2 };
    int medianIdx{ getMedianIndex(nums[start],start,nums[mid],mid,nums[end],end) };
    std::swap(nums[start], nums[medianIdx]);
    int p1{ start + 1 }, p2{ end };
    int pivot{nums[start]};
    while (p1 <= p2) {
        while (p1 <= p2 && nums[p1] <= pivot) p1++;
        while (p1 <= p2 && nums[p2] >= pivot) p2--;
        if (p1 < p2) {
            std::swap(nums[p1], nums[p2]);
            p1++;
            p2--;
        }
    }
    std::swap(nums[start], nums[p2]);
    quicksortInPlace(nums, start, p2 - 1);
    quicksortInPlace(nums, p2 + 1, end);
}

std::vector<int> bubbleSort(std::vector<int> nums) {
    bool sorted{ false};
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                std::swap(nums[i], nums[i - 1]);
                sorted = false;
            }
        }
    }
    return nums;

}

std::vector<int> selectionSort(std::vector<int> nums){
    for (int i = 0; i < nums.size(); i++) {
        int min{INT_MAX}, midx{};
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] < min) {
                midx = j;   
                min = nums[j];
            }
        }
        std::swap(nums[i], nums[midx]);
    }
    return nums;
}

std::vector<int> insertionSortQ(std::vector<int> nums){
    //Not clear why would I do this with insertions and not swapping, unless you do memcpy from index to index, which would make sense in C
    for (int i = 1; i < nums.size(); i++) {
        int c{ i };
        for (int j = i - 1; j >= 0; j--) {
            if (nums[j] > nums[c]) {
                std::swap(nums[j], nums[c]);
                c = j;
            }
            else break;
        }
    }
    return nums;
}

std::vector<int> heapSort(std::vector<int> nums){
    makeMaxHeap(nums,nums.size());
    for (int i = nums.size()-1; i >=0 ; i--) {
        std::swap(nums[0], nums[i]);
        maxHeapify(nums, 0,i);
    }
    return nums;
}
