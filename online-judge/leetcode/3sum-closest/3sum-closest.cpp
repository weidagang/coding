#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int> &num, int target) {
        int closest = num[0] + num[1] + num[2];

        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size() - 2; ++i) {
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];

                if (std::abs(sum - target) < std::abs(closest - target)) {
                    closest = sum;
                }
                
                if (sum == target) {
                    break;
                }
                else if (sum < target) {
                    ++j;
                }
                else {
                    --k; 
                }
            }
        }

        return closest;
    }
};

void test(int a[], int n, int target) {
    std::vector<int> nums;
    nums.assign(a, a + n);

    Solution s;
    int closet = s.threeSumClosest(nums, target);
    printf("%d\n", closet);
}

int main() {
    {
        int a[] = { -1, 2, 1, -4 };
        test(a, sizeof(a)/sizeof(a[0]), 1);
    }

    {
        int a[] = { -1, 2, 1, -4 };
        test(a, sizeof(a)/sizeof(a[0]), 0);
    }

    {
        int a[] = { -1, 2, 1, -4 };
        test(a, sizeof(a)/sizeof(a[0]), -4);
    }
}
