#include <stack>

#ifndef BINARY_TREE_ITERATOR
#define BINARY_TREE_ITERATOR

/*
class Node {
    public: 
        Node* left();
        Node* right();
    ...
};
*/

template<typename Node>
class BinaryTreeIterator {
    public:
        virtual Node* next() = 0;
        virtual bool hasNext() = 0;
};

template<typename Node>
class PreOrderIterator : public BinaryTreeIterator<Node> {
    public:
        PreOrderIterator (Node* node) {
            if (NULL == node) {
                return;
            }
            mStack.push(node);
        }

        virtual Node* next() {
            if (mStack.empty()) {
                return NULL;
            }

            Node *top = mStack.top();
            mStack.pop();

            if (NULL != top->right()) {
                mStack.push(top->right());
            }

            if (NULL != top->left()) {
                mStack.push(top->left());
            }


            return top;
        }

        virtual bool hasNext() {
            return !mStack.empty();
        }
    private:
        std::stack<Node*> mStack;
};

template<typename Node>
class InOrderIterator : public BinaryTreeIterator<Node> {
    public:
        InOrderIterator(Node *node) {
            Node *current = node;
            while (NULL != current) {
                mStack.push(current);
                current = current->left();
            }
        }

        virtual Node* next() {
            if (mStack.empty()) {
                return NULL;
            }

            Node *top = mStack.top();
            mStack.pop();
            if (NULL != top->right()) {
                Node *current = top->right();
                while (NULL != current) {
                    mStack.push(current);
                    current = current->left();
                }
            }

            return top;
        }

        virtual bool hasNext() {
            return !mStack.empty();
        }

    private:
        std::stack<Node*> mStack;
};

template<typename Node>
class PostOrderIterator : public BinaryTreeIterator<Node> {
    public:
        PostOrderIterator (Node* node) {
            Node *current = node;
            while (NULL != current) {
                mStack.push(current);
                current = current->left();
            }
        }

        virtual Node* next() {
            if (mStack.empty()) {
                return NULL;
            }

            Node *top = mStack.top();
            mStack.pop();
            if (!mStack.empty() && top == mStack.top()->left()) {
                Node *current = mStack.top()->right();
                while (NULL != current) {
                    mStack.push(current);
                    current = current->left();
                }
            }
            return top;
        }

        virtual bool hasNext() {
            return !mStack.empty();
        }

    private:
        std::stack<Node*> mStack;
};

#endif
