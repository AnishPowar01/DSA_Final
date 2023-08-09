class Solution {
public:
    // Helper function to find the maximum amount that can be robbed from the binary tree rooted at 'root'.
    int solve(TreeNode* root, unordered_map<TreeNode*, int>& dp) {
        if (root == NULL) {
            return 0; // Base case: If the node is NULL, no money can be robbed from it.
        }

        if (dp[root]) {
            return dp[root]; // If the result for the current node is already calculated, return it from the cache.
        }

        // Rob the current node and the grandchildren (skip the children).
        int robIt = root->val;
        if (root->left != NULL) {
            robIt += solve(root->left->left, dp) + solve(root->left->right, dp);
        }
        if (root->right != NULL) {
            robIt += solve(root->right->left, dp) + solve(root->right->right, dp);
        }

        // Do not rob the current node and only consider robbing from the children.
        int not_rob = solve(root->left, dp) + solve(root->right, dp);

        // The maximum amount that can be robbed from the binary tree rooted at 'root'
        // will be the maximum of robbing the current node and not robbing the current node.
        return dp[root] = max(robIt, not_rob);
    }

    // Main function to find the maximum amount that can be robbed from the binary tree.
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp; // Cache to store previously calculated results.
        return solve(root, dp); // Call the 'solve' function to find the maximum amount that can be robbed.
    }
};
