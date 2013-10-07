#include <deque>
#include <algorithm>
#include <cstdio>

const int MAX_N = 1000 * 1000;

int n, w;
int a[MAX_N];

int input() {
    n = 0;
    w = 0;

    if (0 == scanf("%d %d", &n, &w) || n <= 0) {
        return 1;
    }
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
}

int main() {
    while (0 == input()) {
        std::deque<std::pair<int, int> > queue;

        for (int i = 0; i < w; ++i) {
            while (queue.size() > 0 && queue.back().first < a[i]) {
                queue.pop_back();
            }

            queue.push_back(std::make_pair(a[i], i));
        }
        printf("%d ", queue.front().first);

        for (int i = w; i < n; ++i) {
            if (queue.size() > 0 && queue.front().second < i - w + 1) {
                queue.pop_front();
            }

            while (queue.size() > 0 && queue.back().first < a[i]) {
                queue.pop_back(); 
            }

            queue.push_back(std::make_pair(a[i], i));
            printf("%d ", queue.front().first);
        }

        printf("\n");
    }
    return 0;
}
