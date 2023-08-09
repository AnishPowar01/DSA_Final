/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to find the maximum sum of a path starting from the current node and ending at any node in its subtree.
    int solve(TreeNode* root, int& maxi) {
        if (root == NULL) {
            return 0; // Base case: If the node is NULL, the path sum is zero.
        }

        // Recursively find the maximum sum of a path starting from the left and right subtrees.
        // If the sum is negative, set it to zero as it won't contribute to the maximum path.
        int left = max(0, solve(root->left, maxi));
        int right = max(0, solve(root->right, maxi));

        // Update the maximum path sum found so far by considering three possibilities:
        // 1. The path goes through the current node and extends to its left and right subtrees.
        // 2. The path starts from the current node and extends to either its left or right subtree.
        // 3. The path only includes the current node.
        maxi = max(maxi, root->val + left + right);

        // Return the maximum path sum starting from the current node and extending to either its left or right subtree.
        return root->val + max(left, right);
    }

    // Main function to find the maximum path sum in the binary tree.
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; // Initialize the maximum path sum to the minimum integer value.

        // Call the 'solve' function to calculate the maximum path sum.
        solve(root, maxi);

        // Return the maximum path sum found in the binary tree.
        return maxi;
    }
};
