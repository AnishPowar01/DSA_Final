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
    // Function to find the maximum depth of a binary tree (height of the tree).
    int maxDepth(TreeNode* root) {

        // Base case: If the root is NULL (empty tree), the depth is 0.
        if(root == NULL) {
            return 0;
        }

        // Recursively find the maximum depth of the left and right subtrees.
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        // The depth of the current node is the maximum of the depths of its left and right subtrees,
        // plus 1 for the current node itself.
        return 1 + max(left, right);
    }
};
