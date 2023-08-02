class Solution {
public:
    // Helper function to find the extreme right node in the left subtree.
    TreeNode* findExtremeRight(TreeNode* root) {
        if (root->right == NULL) {
            return root; // Base case: If the right child is NULL, return the current node.
        }

        // Recursively find the extreme right node in the left subtree.
        return findExtremeRight(root->right);
    }

    // Helper function to perform the deletion operation for the main delete function.
    TreeNode* mainDeleteFunction(TreeNode* root) {
        if (root->left == NULL) {
            return root->right; // If the left child is NULL, return the right child (right subtree).
        }

        if (root->right == NULL) {
            return root->left; // If the right child is NULL, return the left child (left subtree).
        }

        TreeNode* rightPart = root->right; // Save the right subtree.

        TreeNode* extremeRight = findExtremeRight(root->left); // Find the extreme right node in the left subtree.

        extremeRight->right = rightPart; // Attach the right subtree to the extreme right node.

        return root->left; // Return the updated left subtree.
    }

    // Main function to delete a node with the given key in the binary search tree (BST).
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL; // Base case: If the root is NULL, return NULL (empty tree).
        }

        // If the key is found at the root node, perform the deletion operation using the 'mainDeleteFunction'.
        if (root->val == key) {
            return mainDeleteFunction(root);
        }

        // Otherwise, perform the BST search to find the node to be deleted.
        TreeNode* temp = root;
        while (temp != NULL) {
            if (temp->val > key) {
                if (temp->left != NULL && temp->left->val == key) {
                    temp->left = mainDeleteFunction(temp->left); // Perform the deletion on the left subtree.
                    break;
                } else {
                    temp = temp->left; // Move to the left child.
                }
            } else {
                if (temp->right != NULL && temp->right->val == key) {
                    temp->right = mainDeleteFunction(temp->right); // Perform the deletion on the right subtree.
                    break;
                } else {
                    temp = temp->right; // Move to the right child.
                }
            }
        }

        return root; // Return the updated root of the BST after deletion.
    }
};
