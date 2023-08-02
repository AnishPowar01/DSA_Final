#include <bits/stdc++.h>
using namespace std;
class AVL
{

public:
    class Node
    {
    public:
        int value;
        Node *left;
        Node *right;
        int height;

        Node(int value)
        {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
            this->height = 0;
        }

        // Node(int value) : value(value), left(nullptr), right(nullptr), height(0){}
    };

    Node *root;

    // AVL;
    AVL()
    {
        this->root = nullptr;
    }

    int height()
    {
        return height(root);
    }

private:
    int height(Node *root)
    {
        if (root == nullptr)
        {
            return -1;
        }

        return root->height;
    }

public:
    void insert(int value)
    {
        root = insert(value, root);
    }

private:
    Node *insert(int val, Node *node)
    {

        if (node == nullptr)
        {
            node = new Node(val);
            return node;
        }

        if (val < node->value)
        {
            node->left = insert(val, node->left);
        }
        else
        {
            node->right = insert(val, node->right);
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        return rotate(node);
    }

    Node* rotate(Node* node) {
        if (height(node->left) - height(node->right) > 1) {
            // left heavy
            if (height(node->left->left) - height(node->left->right) > 0) {
                // left left case
                return rightRotate(node);
            }
            if (height(node->left->left) - height(node->left->right) < 0) {
                // left right case
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        if (height(node->left) - height(node->right) < -1) {
            // right heavy
            if (height(node->right->left) - height(node->right->right) < 0) {
                // right right case
                return leftRotate(node);
            }
            if (height(node->right->left) - height(node->right->right) > 0) {
                // left right case
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    Node* rightRotate(Node* parent)
    {

        Node* child = parent->left;
        Node* subTree = child->right;

        child->right = parent;

        parent->left = subTree;

        parent->height = max(height(parent->left), height(parent->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;
    }

    Node* leftRotate(Node* parent)
    {
        Node * child = parent->right;
        Node* subtree = child->left;

        child->left = parent;
        parent->right = subtree;

         parent->height = max(height(parent->left), height(parent->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;

    }

public:
    void populTE(int *nums, int size)
    {
        for (int i = 0; i < size; i++)
        {
            this->insert(nums[i]);
        }
    }

    void populatedSorted(int *nums, int start, int end)
    {
        if (start >= end)
        {
            return;
        }

        int mid = (start + end) / 2;

        this->insert(nums[mid]);

        populatedSorted(nums, start, mid);
        populatedSorted(nums, mid + 1, end);
    }

    void display()
    {
        display(this->root, "Root Node: ");
    }

private:
    void display(Node *node, const string &details)
    {
        if (node == nullptr)
        {
            return;
        }

        cout << details << node->value << endl;
        display(node->left, "Left child of " + to_string(node->value) + " : ");
        display(node->right, "Right child of " + to_string(node->value) + " : ");
    }

public:
    bool isEmpty()
    {
        return root == nullptr;
    }

    bool balanced()
    {
        return balanced(root);
    }

private:
    bool balanced(Node *node)
    {
        if (node == nullptr)
        {
            return true;
        }
        return abs(height(node->left) - height(node->right)) <= 1 && balanced(node->left) && balanced(node->right);
    }
};
int main()
{
    AVL avl;


    for (int i = 0; i < 5; i++)
    {
        avl.insert(i);
    }

    // avl.display();

    cout<<avl.height();

    
    return 0;
}