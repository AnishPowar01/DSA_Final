#include <bits/stdc++.h>
using namespace std;
class BTS
{
public:
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
    };

    BTS()
    {
        root = NULL;
    }

private:
    Node *root;

public:
    void insert(int data)
    {
        root = insert(data, root);
    }

    void display()
    {
        display(root);
    }

    bool isEmpty()
    {
        return isEmpty(root);
    }

    bool isBalance()
    {
        int ans = isBalace(root);

        return ans == -1 ? false : true;
    }

private:
    Node *insert(int value, Node *node)
    {
        if (node == NULL)
        {
            node = new Node(value);
            return node;
        }
        if (value < node->data)
        {
            node->left = insert(value, node->left);
        }
        else if (value > node->data)
        {
            node->right = insert(value, node->right);
        }

        return node;
    }

    void display(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }

    bool isEmpty(Node *root)
    {
        return root == NULL;
    }

    int isBalace(Node *root)
    {
        if (root == NULL)
        {
            return 1;
        }

        int leftHeight = isBalace(root->left);
        if (leftHeight == -1)
        {
            return false;
        }

        int rightHeight = isBalace(root->right);

        if (rightHeight == -1)
        {
            return false;
        }

        if (abs(leftHeight - rightHeight) > 1)
        {
            return -1;
        }

        return leftHeight + rightHeight + 1;
    }
};
int main()
{
    BTS *ns = new BTS();

    ns->insert(50);
    ns->insert(60);
    ns->insert(80);
    ns->insert(90);
    ns->insert(1000);
    ns->insert(10);
    ns->insert(20);
    ns->insert(30);
    ns->insert(40);
    ns->insert(80);
    ns->insert(2);
    ns->insert(1);
    ns->display();

    cout<<ns->isBalance()<<" ";

    return 0;
}