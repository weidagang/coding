#include <cstdio>
#include <queue>

#include "binary_tree_iterator.hpp"

struct Node {
    int mValue;
    Node *mLeft;
    Node *mRight;

    Node() : mValue(0), mLeft(NULL), mRight(NULL) {
    }

    ~Node() {
        if (NULL != mLeft) {
            delete mLeft;
        }

        if (NULL != mRight) {
            delete mRight;
        }
    }
    
    Node* left() {
        return mLeft;
    }

    Node* right() {
        return mRight;
    }
};

int main() {
    // test setup    
    std::queue<Node*> q;
    
    Node *root = new Node();
    q.push(root);
    
    const int n = 15;
    int i = 1;
    while (i <= n) {
        Node *current = q.front();
        q.pop(); 
        
        current->mValue = i++;
        
        if (2 * current->mValue <= n) {
            current->mLeft = new Node();
            q.push(current->mLeft);
        }
        
        if (2 * current->mValue + 1 <= n) {
            current->mRight = new Node();
            q.push(current->mRight);
        }
    }
    
    // in-order iterator
    {
        printf("+ In-order traversal:\n");
        InOrderIterator<Node> iterator(root);
        while (iterator.hasNext()) {
            Node *node = iterator.next();
            printf("%d ", node->mValue);
        }
        printf("\n");
        printf("- In-order traversal\n");
    }
    

    // pre-order iterator
    {
        printf("+ Pre-order traversal:\n");
        PreOrderIterator<Node> iterator(root);
        while (iterator.hasNext()) {
            Node *node = iterator.next();
            printf("%d ", node->mValue);
        }
        printf("\n");
    }
    printf("- Pre-order traversal\n");

    // post-order iterator
    {
        printf("+ Post-order traversal:\n");
        PostOrderIterator<Node> iterator(root);
        while (iterator.hasNext()) {
            Node *node = iterator.next();
            printf("%d ", node->mValue);
        }
        printf("\n");
    }
    printf("- Post-order traversal\n");
    return 0;
}
