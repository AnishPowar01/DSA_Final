
class Solution {
public:
    // Helper function to calculate the height of the tree in a specific direction (left or right).
    int Height(TreeNode* root, int direction) {
        int count = 0;

        if (root == NULL) {
            return 0; // Base case: If the node is NULL, return 0 height.
        }

        if (direction == 0) { // Calculate height towards the left direction.
            TreeNode* leftPointer = root;
            while (leftPointer) {
                count++; // Increment the count for each level traversed towards the left.
                leftPointer = leftPointer->left; // Move to the left child.
            }
        } else { // Calculate height towards the right direction.
            count = 0;
            TreeNode* rightPointer = root;
            while (rightPointer) {
                count++; // Increment the count for each level traversed towards the right.
                rightPointer = rightPointer->right; // Move to the right child.
            }
        }
        return count; // Return the height calculated in the specified direction.
    }

    // Main function to count the number of nodes in the binary tree.
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0; // Base case: If the tree is empty, return 0.
        }

        int leftH = Height(root, 0); // Calculate the height of the left subtree.
        int rightH = Height(root, -1); // Calculate the height of the right subtree.

        if (leftH == rightH) {
            // If the height of the left and right subtrees are the same, the tree is a perfect binary tree.
            // Return the number of nodes using the formula: 2^leftH - 1.
            return (1 << leftH) - 1;
        }

        // If the tree is not a perfect binary tree, calculate the number of nodes recursively.
        // Return 1 for the root node plus the count of nodes in the left and right subtrees.
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
