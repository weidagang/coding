#include <cstdio>

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int idxA = m - 1;
        int idxB = n - 1;
        int idx = m + n - 1;
        while (idxB >= 0) {
            if (idxA >= 0 && A[idxA] > B[idxB]) {
                A[idx--] = A[idxA--];
            }
            else {
                A[idx--] = B[idxB--];
            }
        }
    }
};

int main() {
    Solution s;

    {
        int A[10] = { 1, 3, 5, 7, 9 };
        int B[] = { 2, 4, 6 };
        int m = 5;
        int n = 3;
        
        s.merge(A, m, B, n);

        for (int i = 0; i < m + n; ++i) {
            printf("%d ", A[i]);
        }

        printf("\n");
    }

    {
        int A[10] = { 5, 6, 7 };
        int B[] = { 1, 2, 3, 4 };
        int m = 3;
        int n = 4;
        
        s.merge(A, m, B, n);

        for (int i = 0; i < m + n; ++i) {
            printf("%d ", A[i]);
        }

        printf("\n");
    }

    {
        int A[10] = { 1, 2, 3, 4 };
        int B[] = { 5, 6, 7 };
        int m = 4;
        int n = 3;
        
        s.merge(A, m, B, n);

        for (int i = 0; i < m + n; ++i) {
            printf("%d ", A[i]);
        }

        printf("\n");
    }

    {
        int A[10] = { };
        int B[] = { };
        int m = 0;
        int n = 0;
        
        s.merge(A, m, B, n);

        for (int i = 0; i < m + n; ++i) {
            printf("%d ", A[i]);
        }

        printf("\n");
    }

    {
        int A[10] = { 1 };
        int B[] = { };
        int m = 1;
        int n = 0;
        
        s.merge(A, m, B, n);

        for (int i = 0; i < m + n; ++i) {
            printf("%d ", A[i]);
        }

        printf("\n");
    }

    {
        int A[10] = { };
        int B[] = { 1 };
        int m = 0;
        int n = 1;
        
        s.merge(A, m, B, n);

        for (int i = 0; i < m + n; ++i) {
            printf("%d ", A[i]);
        }

        printf("\n");
    }

    return 0;
}
