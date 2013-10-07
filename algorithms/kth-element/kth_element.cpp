#include <iostream>
#include <vector>
#include <algorithm>

int nums[] = { 1, 5, 1, 2, 4, 5, 3, 6, 7, 9, 8 };
int n = sizeof(nums) / sizeof(nums[0]);

int partition(int fromIdx, int toIdx, int pivotIdx) {
    if (fromIdx == toIdx) {
        return fromIdx;
    }

    std::swap(nums[toIdx], nums[pivotIdx]);
    
    int idx = fromIdx;
    for (int i = fromIdx; i < toIdx; ++i) {
        if (nums[i] < nums[toIdx]) {
            std::swap(nums[i], nums[idx]);
            idx++;
        }
    }

    std::swap(nums[idx], nums[toIdx]);

    return idx;
}

int kth_element(int fromIdx, int toIdx, int k) {
    int idx = partition(fromIdx, toIdx, fromIdx);
    
    int order = idx - fromIdx;

    if (order == k) {
        return idx;
    }
    else if (order > k) {
        return kth_element(fromIdx, idx - 1, k);
    }
    else {
        return kth_element(idx + 1, toIdx, k - order - 1);
    }
}

int main() {
    for (int k = 1; k <= n; ++k) {
        int idx = kth_element(0, n - 1, k - 1);
        std::cout << "The " << k << " th element is: " << nums[idx] << std::endl;
    }
}
