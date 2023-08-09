class Solution {
public:
    // Helper function to calculate the sum of all root-to-leaf numbers in the binary tree.
    int sum(TreeNode* root, int ans) {
        if (root == NULL) {
            return 0; // Base case: If the node is NULL, return 0.
        }

        ans = ans * 10 + root->val; // Update the current sum by appending the current node's value.

        // If the current node is a leaf node, return the current sum.
        if (root->left == NULL && root->right == NULL) {
            return ans;
        }

        // Recursively calculate the sum of all root-to-leaf numbers from the left and right subtrees.
        return sum(root->left, ans) + sum(root->right, ans);
    }

    // Main function to calculate the sum of all root-to-leaf numbers in the binary tree.
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0; // Base case: If the tree is empty, return 0.
        }

        // Call the helper function 'sum' with the initial sum value as 0.
        return sum(root, 0);
    }
};
