#include <algorithm>
#include <cstdio>

#define MAX_N 100000

int n;
int nums[MAX_N];
int left_link[MAX_N];
int right_link[MAX_N];

long long find_max_rectangle() {
    left_link[0] = -1;

    for (int i = 1; i < n; ++i) {
        int idx = i - 1;
        while (idx >= 0 && nums[idx] >= nums[i]) {
            idx = left_link[idx];
        }

        left_link[i] = idx;
    }

    right_link[n-1] = n;
    for (int i = n - 1; i >= 0; --i) {
        int idx = i + 1;
        while (idx < n && nums[idx] >= nums[i]) {
            idx = right_link[idx];
        }
        right_link[i] = idx;
    }

    long long max_sum = 0;
    for (int i = 0; i < n; ++i) {
        if ((long long)nums[i] * (right_link[i] - left_link[i] - 1) > max_sum) {
            max_sum = (long long)nums[i] * (right_link[i] - left_link[i] - 1);
        }
    }

    return max_sum;
}

int main() {
    while (true) {
        scanf("%d", &n);
        if (0 == n) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
            //printf("%d ", nums[i]);
        }
        long long max_rectangle = find_max_rectangle(); 
        printf("%lld\n", max_rectangle);
    }

    return 0;
}
