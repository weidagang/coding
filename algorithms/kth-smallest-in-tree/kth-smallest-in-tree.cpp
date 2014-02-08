#include <cstdio>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int kth_smallest_in_tree(TreeNode *root, int k) {
    if (NULL == root || k < 1) {
        return -1; 
    }

    int i = 0;  
    std::stack<TreeNode*> s;

    bool go_left = true;
    s.push(root);

    while (!s.empty()) {
        TreeNode *top = s.top(); 

        if (go_left) {
            // down to the left most child
            TreeNode *node = top->left;
            while (NULL != node) {
                s.push(node);
                node = node->left;
            }
            go_left = false;
        }
        else {
            s.pop();

            if (++i == k) {
                return top->val;
            }

            // visit the right branch
            if (NULL != top->right) {
                go_left = true;
                s.push(top->right);
            }
        }

    }

    return -1;
}

TreeNode* make_tree(int nodes[], int n) {
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
    for (int i = 0; i < n; ++i) {
        int val = kth_smallest_in_tree(root, i + 1);
        printf("%d ", val);
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
        int nodes[] = { 2, 1, 3 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }

    {
        int nodes[] = { 4, 2, 6, 1, 3, 5, 7 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }

    {
        int nodes[] = { 4, 2, 6, -1, 3, 5, -1 };
        int n = sizeof(nodes)/sizeof(nodes[0]);
        test(nodes, n);
    }

    return 0;
}
