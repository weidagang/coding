#include <queue>
#include <algorithm>
#include <cstdio>

const int MAX_N = 1000 * 1000;

int n, w;
int a[MAX_N];

struct Node {
    int m_value;
    int m_index;

    Node(int v, int i) : m_value(v), m_index(i) {
    }

    bool operator<(const Node& rhs) const {
        return this->m_value < rhs.m_value;
    }
};

int input() {
    n = 0;
    w = 0;

    if (0 == scanf("%d %d", &n, &w) || n <= 0) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d ", &a[i]);
    }

    return 0;
}


int main() {
    int icase = 0;

    while (0 == input()) {
        printf("case %d:\n", ++icase);

        std::priority_queue<Node> q;
        
        for (int i = 0; i < w; ++i) {
            q.push(Node(a[i], i));
        }

        printf("%d ", q.top().m_value);
       
        for (int i = w; i < n; ++i) {
            q.push(Node(a[i], i));
            while (!q.empty() && q.top().m_index < i - w + 1) {
                q.pop();
            }
            printf("%d ", q.top().m_value);
        }

        printf("\n\n");
    }

    return 0;
}
