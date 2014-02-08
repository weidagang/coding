#include <iostream>
#include <vector>
#include <algorithm>

int nums[] = { 1, 5, 1, 2, 4, 5, 3, 6, 7, 9, 8 };
const int N = sizeof(nums) / sizeof(nums[0]);

// partition the array[fromIdx, toIdx] into 2 parts, 
// where the left is < nums[pivotIdx], the right is >= nums[pivotIdx],
// return the final index of the pivot item
int partition(int fromIdx, int toIdx, int pivotIdx) {
    if (fromIdx == toIdx) {
        return fromIdx;
    }
    
    // swap pivot to the end of the array
    std::swap(nums[toIdx], nums[pivotIdx]);
    pivotIdx = toIdx;

    // for each k < idx => nums[k] < nums[pivotIdx]
    int idx = fromIdx;  
    for (int i = fromIdx; i < toIdx; ++i) {
        if (nums[i] < nums[pivotIdx]) {
            std::swap(nums[i], nums[idx]);
            idx++;
        }
    }
    
    // swap the pivot to the middle
    std::swap(nums[idx], nums[toIdx]);

    return idx;
}

// find the kth smallest number in nums[fromIdx, toIdx] (k starts from 0)
int kth_element(int fromIdx, int toIdx, int k) {
    // partition the array into 2 parts at random
    int idx = partition(fromIdx, toIdx, fromIdx);

    int m = idx - fromIdx;

    if (m == k) {
        return idx;
    }
    else if (m > k) {
        return kth_element(fromIdx, idx - 1, k);
    }
    else {
        // (k - m - 1) means we skipped (m + 1) items of the left part
        return kth_element(idx + 1, toIdx, k - m - 1);
    }
}

int main() {
    for (int k = 1; k <= N; ++k) {
        int idx = kth_element(0, N - 1, k - 1);
        std::cout << "The " << k << " th element is: " << nums[idx] << std::endl;
    }
}
