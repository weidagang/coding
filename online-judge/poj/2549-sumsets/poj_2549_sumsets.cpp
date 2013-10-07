#include <cstdio>
#include <algorithm>

const int MAX_N = 1000;

int n;
int a[MAX_N];

int input() {
    scanf("%d", &n);
    if (0 == n) {
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    return 1;
}

void find_max() {
    if (n < 4) {
        printf("no solution\n");
        return;
    }
        
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }

            int h = j + 1;
            int t = n - 1;

            while (h < t) {
                if (h == i) {
                    ++h;
                    continue;
                }

                if (t == i) {
                    --t;
                    continue;
                }

                const int sum = a[j] + a[h] + a[t];

                if (sum == a[i]) {
                    printf("%d\n", sum);
                    return;
                }

                if (sum < a[i]) {
                    ++h;
                }
                else {
                    --t;
                }
            }
        }
    }

    printf("no solution\n");
}

int main() {
    while (input()) {
        std::sort(a, a + n);
        find_max();
    }
    return 0;
}
