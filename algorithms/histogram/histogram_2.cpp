#include <algorithm>
#include <cstdio>
#include <deque>

#define MAX_N 100000

int n;
int h[MAX_N + 1];

struct Node {
    int start_idx;
    int idx;
};

long long find_max_rectangle() {
    long long max_sum = 0;
    std::deque<Node> q;

    h[n] = 0;

    for (int i = 0; i <= n; ++i) {
        Node current;
        current.idx = i;
        current.start_idx = i;
        
        while (!q.empty() && h[i] <= h[q.back().idx]) {
            current.start_idx = q.back().start_idx;

            long long sum = ((long long)h[q.back().idx]) * (i - q.back().start_idx);
            max_sum = std::max(max_sum, sum);
            q.pop_back();
        }
        
        q.push_back(current);
    }
    
    return max_sum;
}

int main() {
    while (true) {
        // input
        scanf("%d", &n);
        if (0 == n) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &h[i]);
        }

        long long max_rectangle = find_max_rectangle(); 
        printf("%lld\n", max_rectangle);
    }

    return 0;
}
