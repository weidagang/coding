#include <cstdio>
#include <cstring>
#include <memory>
#include <algorithm>

#define N 1000
#define OK 0
#define ERROR 1

struct Node {
    int m_value;
    int m_row;
    int m_column;

    Node() {
    }

    Node(int value, int row, int column) {
        m_value = value;
        m_row = row;
        m_column = column;
    }
};

class BinaryHeap {
    private: 
        const unsigned int m_capacity;
        Node* const m_nodes;
        unsigned int m_size;

    public:
        BinaryHeap(unsigned int capacity) : 
                m_capacity(capacity)
              , m_nodes(new Node[capacity])
        {
            m_size = 0;
        }

        ~BinaryHeap() {
            delete m_nodes;
        }

        int insert(Node& node) {
            if (m_size >= m_capacity) {
                return ERROR;
            }

            m_nodes[m_size++] = node;
            _adjust_insert();
        }

        int pop(Node& out_node) {
            if (m_size <= 0) {
                return ERROR;
            }

            out_node = m_nodes[0];
            std::swap(m_nodes[0], m_nodes[m_size - 1]);
            --m_size;
            _adjust_pop();
        }

    private:
        void _adjust_insert() {
            int idx = m_size - 1;
            while (idx > 0) {
                int parent = (idx - 1) / 2;
                if (m_nodes[parent].m_value > m_nodes[idx].m_value) {
                    std::swap(m_nodes[parent], m_nodes[idx]);
                    idx = parent;
                }
                else {
                    break;
                }
            }
        }

        void _adjust_pop() {
            int idx = 0; 
            while (idx < m_size) {
                int min_idx = idx;

                int left = idx * 2 + 1; 
                if (left < m_size && m_nodes[left].m_value < m_nodes[min_idx].m_value) {
                    min_idx = left;
                }
                int right = idx * 2 + 2;
                if (right < m_size && m_nodes[right].m_value < m_nodes[min_idx].m_value) {
                    min_idx = right;
                }

                if (min_idx == idx) {
                    break;
                }
                else {
                    std::swap(m_nodes[idx], m_nodes[min_idx]);
                    idx = min_idx;
                }
            }
        }
};

int matrix[N][N];
char visited[N][N];
Node heap[N * N];
int k;
int m; /* num of rows */
int n; /* num of columns */

int read_test_case() {
    int i = 0;
    int j = 0;
    int rc = 0;
    rc = scanf("%d", &k);
    if (rc <= 0) {
        return 0;
    }

    // printf("k: %d\n", k);

    rc = scanf("%d %d", &m, &n);
    if (rc <= 0) {
        return 0;
    }

    // printf("m: %d, n: %d\n", m, n);

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &matrix[i][j]);
            // printf("%d ", matrix[i][j]);
        }
        // printf("\n");
    }

    memset(visited, 0, sizeof(visited));

    return 1; 
}

int find_kth() {
    BinaryHeap heap(m * n);

    Node node;

    node = Node(matrix[0][0], 0, 0);
    heap.insert(node);
    visited[0][0] = 1;

    for (int i = 0; i < k; ++i) {
        heap.pop(node);

        if (node.m_row + 1 < m && !visited[node.m_row + 1][node.m_column]) {
            Node open_node(matrix[node.m_row + 1][node.m_column], node.m_row + 1, node.m_column);
            heap.insert(open_node);
            visited[node.m_row + 1][node.m_column] = 1;
        }

        if (node.m_column + 1 < n && !visited[node.m_row][node.m_column + 1]) {
            Node open_node(matrix[node.m_row][node.m_column + 1], node.m_row, node.m_column + 1);
            heap.insert(open_node);
            visited[node.m_row][node.m_column + 1] = 1;
        }
    }

    return node.m_value;
}

int main() {
    while (read_test_case()) {
        int kth = find_kth();
        printf("%d\n", kth);
    }
    return 0;
}
