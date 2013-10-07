#include <cstdio>
#include <algorithm>

#define MAX 1000000

int n;
int v[MAX];

void sort_odd_even() {
    int idx_odd = -1;
    int idx_even = -1;

    for (int i = 0; i < n; ++i) {
        if (1 == v[i] % 2) {
            idx_odd = i;
            break;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (0 == v[i] % 2) {
            idx_even = i;
            break;
        }
    }

    // trivial case
    if (idx_odd < 0 || idx_even < 0) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", v[i]);
        }
        return;
    }

    // notrivial case
    while (idx_odd < n) {
        if (idx_odd > idx_even) {
            std::swap(v[idx_odd], v[idx_even]);
            std::swap(idx_odd, idx_even);
        }
        else {
            ++idx_odd;
            while (idx_odd < n && 0 == v[idx_odd] % 2) {
                ++idx_odd;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    while (EOF != scanf("%d", &n)) {
        printf("\n");
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            printf("%d ", v[i]);
        }
        printf("\n");
        sort_odd_even();
    }

    return 0;
}
