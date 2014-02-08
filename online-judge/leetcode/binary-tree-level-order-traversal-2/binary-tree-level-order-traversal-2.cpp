#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<std::vector<int> > levelOrderBottom(TreeNode *root) {
        std::vector<std::vector<int> > result;
        std::queue<std::pair<TreeNode*, int> > q;         

        if (NULL != root) {
            q.push(std::make_pair(root, 0));
            while (!q.empty()) {
                std::pair<TreeNode*, int> front = q.front();
                q.pop();

                TreeNode* node = front.first;
                int val = node->val;
                int level = front.second;
                if (result.size() <= level) {
                    result.push_back(std::vector<int>());
                }
                result[level].push_back(val);

                if (NULL != node->left) {
                    q.push(std::make_pair(node->left, level + 1));
                }

                if (NULL != node->right) {
                    q.push(std::make_pair(node->right, level + 1));
                }
            }
        }

        std::reverse(result.begin(), result.end());

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
    std::vector<std::vector<int> > result = s.levelOrderBottom(root);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    {
        int nodes[] = { 3, 9, 20, -1, -1, 15, 7 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }

    {
        int nodes[] = { 3 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }

    {
        int nodes[] = { 1, 2, 3, 4, 5, 6, 7 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }
    return 0;
}
