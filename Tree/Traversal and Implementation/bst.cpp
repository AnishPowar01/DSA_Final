#include<bits/stdc++.h>
using namespace std;

// BST node class
class BST {
public:
    int data;
    BST* left = NULL;
    BST* right = NULL;

    // Constructor
    BST(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to create a BST
BST* createTree(BST* &root, int data) {
    if (root == NULL) {
        root = new BST(data);
        return root;
    }

    if (data > root->data) {
        root->right = createTree(root->right, data);
    }
    else {
        root->left = createTree(root->left, data);
    }

    return root;
}

// Function to take input and create a BST
void takeInput(BST* &root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = createTree(root, data);
        cin >> data;
    }
}

// Function to print the BST in in-order traversal
void print(BST* &root) {
    if (root == NULL) {
        return;
    }

    print(root->left);      // Print left subtree
    cout << root->data << " ";
    print(root->right);     // Print right subtree
}

// Function to check if a value is present in the BST
bool isPresent(BST* &root, int data) {
    // BST is empty or the value is found
    if (root == NULL) {
        return false;
    }

    if (root->data == data) {
        cout << "Present" << endl;
        return true;
    }

    if (data > root->data) {
        return isPresent(root->right, data);
    }
    else {
        return isPresent(root->left, data);
    }

    return false;   // Value not found
}

int main() {
    BST* root = NULL;

    cout << "Enter data to insert into the tree: ";
    takeInput(root);

    cout << "In-order traversal of the tree: ";
    print(root);

    int search;
    cout << "\nEnter the data to search: ";
    cin >> search;

    if (isPresent(root, search)) {
        cout << "The value " << search << " is present in the tree." << endl;
    }
    else {
        cout << "The value " << search << " is not present in the tree." << endl;
    }

    return 0;
}