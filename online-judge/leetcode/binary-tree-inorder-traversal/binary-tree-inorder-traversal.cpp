#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> result;

        if (NULL == root) {
            return result;
        }

        std::stack<TreeNode*> s;

        bool go_left = true; 
        s.push(root);
        
        while (!s.empty()) {
            TreeNode *node = s.top();

            if (go_left) {
                while (node->left) {
                    s.push(node->left);
                    node = node->left;
                }
                go_left = false;
            }
            else {
                s.pop();
                result.push_back(node->val);

                if (node->right) {
                    s.push(node->right);
                    go_left = true;
                }
            }
        }
        
        return result;
    }
};

TreeNode * make_tree(int nodes[], int n) {
    if (0 == n) {
        return NULL;
    }

    TreeNode *root = new TreeNode(nodes[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty()) {
        TreeNode *front = q.front();
        q.pop();

        if (i < n && -1 != nodes[i]) {
            front->left = new TreeNode(nodes[i]);
            q.push(front->left);
        }
        ++i;

        if (i < n && -1 != nodes[i]) {
            front->right = new TreeNode(nodes[i]);
            q.push(front->right);
        }
        ++i;
    }

    return root;
}

void test(int nodes[], int n) {
    TreeNode *root = make_tree(nodes, n);
    Solution s;
    std::vector<int> result = s.inorderTraversal(root);
    for (int i = 0; i < result.size(); ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main() {
    {
        int nodes[] = { 3 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }

    {
        int nodes[] = { 3, 9, 20, -1, -1, 15, 7 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }

    {
        int nodes[] = { 1, 2, 3, 4, 5, 6, 7 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }

    {
        int nodes[] = { 1, -1, 2, 3 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }

    return 0;
}
