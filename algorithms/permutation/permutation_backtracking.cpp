#include<algorithm>
#include<iostream>
#include<iterator>
#include<vector>

int nums[] = { 1, 2, 3, 4 };
int n = sizeof(nums) / sizeof(nums[0]);

void generate(int idx) {
    if (idx == n - 1) {
        for (int i = 0; i < n; ++i) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = idx; i < n; ++i) {
        std::swap(nums[idx], nums[i]);
        generate(idx+1);
        std::swap(nums[idx], nums[i]);
    }
}

int main() {
    generate(0);
    return 0;
}
