#include <cstdio>
#include <algorithm>

// find the kth smallest number from 2 sorted arrays a[a_from, a_to), b[b_from, b_to), k starts from 1
int find_kth(int a[], int a_from, int a_to, int b[], int b_from, int b_to, int k) {
    //printf("find_kth(), k=%d, a_from=%d, a_to=%d, b_from=%d, b_to=%d\n", k, a_from, a_to, b_from, b_to);

    // k is larger than the total number of elements
    if (k > a_to - a_from + b_to - b_from) {
        return -1;
    }
    
    // boundary cases
    if (0 == a_to - a_from) {
        return b[b_from + k - 1];
    }

    if (0 == b_to - b_from) {
        return a[a_from + k - 1];
    }

    if (1 == k) {
        return std::min(a[a_from], b[b_from]);
    }

    int a_mid = a_from + (a_to - a_from) / 2;
    
    // find the idx where b[b_from, idx] <= a[a_from]
    int from = b_from;
    int to = b_to;
    int idx = b_from - 1;

    while (from < to) {
        int i = from + (to - from) / 2;

        if (b[i] <= a[a_mid]) {
            idx = i;
            from = i + 1;
        }
        else {
            to = i;
        }
    }

    //printf("a_from=%d, a_to=%d, a_mid=%d, idx=%d\n", a_from, a_to, a_mid, idx);

    if (a_mid == a_to - 1 && idx == b_to - 1) {
        if (a[a_from] <= b[b_from]) {
            return find_kth(a, a_from + 1, a_to, b, b_from, b_to, k - 1);
        }
        else {
            return find_kth(a, a_from, a_to, b, b_from + 1, b_to, k - 1);
        }
    }

    // kth is in a[a_from, a_mid] or b[b_from, idx]
    if (k <= (a_mid - a_from + 1) + (idx - b_from + 1)) {
        return find_kth(a, a_from, a_mid + 1, b, b_from, idx + 1, k);
    }
    
    // kth is in a[a_mid + 1, a_to] or b[idx + 1, b_to]
    return find_kth(a, a_mid + 1, a_to, b, idx + 1, b_to, k - (a_mid - a_from + 1) - (idx - b_from + 1));
}

void test(int a[], int n, int b[], int m) {
    for (int k = 1; k <= n + m; ++k) {
        int val = find_kth(a, 0, n, b, 0, m, k);
        printf("%d ", val);
    }
    printf("\n");
}

int main() {
    {
        int a[] = { 1, 3, 5, 7, 9 };
        int b[] = { 2, 4, 6, 8 };
        test(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
    }

    {
        int a[] = { 1, 2, 3 };
        int b[] = { 4, 5, 6 };
        test(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
    }

    {
        int a[] = { 4, 5, 6 };
        int b[] = { 1, 2, 3 };
        test(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
    }

    {
        int a[] = {  };
        int b[] = { 1, 2, 3 };
        test(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0]));
    }
    return 0;
}
