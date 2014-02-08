#include<cstdio>
#include<vector>
#include<algorithm>

class Solution {
    public:
        int trap(int A[], int n) {
            if (0 == n || 1 == n) {
                return 0;
            }
            std::vector<int> maxLeftHeight(n);
            std::vector<int> maxRightHeight(n);

            maxLeftHeight[0] = 0;
            for (int i = 1; i < n; ++i) {
                maxLeftHeight[i] = std::max(maxLeftHeight[i-1], A[i-1]);
            }

            maxRightHeight[n-1] = 0;
            for (int i = n - 2; i >= 0; --i) {
                maxRightHeight[i] = std::max(maxRightHeight[i+1], A[i+1]);
            }

            int sum = 0;
            for (int i = 0; i < n; ++i) {
                int boundaryHeight = std::min(maxLeftHeight[i], maxRightHeight[i]);
                if (boundaryHeight > A[i]) {
                    sum += boundaryHeight - A[i];
                }
            }

            return sum;
    }
};

int main() {
    Solution s;
    
    {
        int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        int sum = s.trap(A, sizeof(A)/sizeof(A[0]));
        printf("%d\n", sum);
    }

    {
        int A[] = {0, 1, 2, 3, 4, 5};
        int sum = s.trap(A, sizeof(A)/sizeof(A[0]));
        printf("%d\n", sum);
    }

    {
        int A[] = {};
        int sum = s.trap(A, sizeof(A)/sizeof(A[0]));
        printf("%d\n", sum);
    }

    {
        int A[] = {1};
        int sum = s.trap(A, sizeof(A)/sizeof(A[0]));
        printf("%d\n", sum);
    }

    {
        int A[] = {1, 2};
        int sum = s.trap(A, sizeof(A)/sizeof(A[0]));
        printf("%d\n", sum);
    }

    {
        int A[] = {10, 0, 0, 10, 5, 10, 4, 100};
        int sum = s.trap(A, sizeof(A)/sizeof(A[0]));
        printf("%d\n", sum);
    }

    return 0;
}
