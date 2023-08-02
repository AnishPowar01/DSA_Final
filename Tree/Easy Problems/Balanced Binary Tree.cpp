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
    int solve(TreeNode* root)
    {
        if(root == NULL)
        {
            return 1;
        }

        int leftHeight = solve(root->left);

        if(leftHeight == -1)
        {
            return -1;
        }

        int rightHeight  = solve(root->right);

        if(rightHeight==-1)
        {
            return -1;
        }

        if(abs(rightHeight - leftHeight) > 1)
        {
            return -1;
        }


        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {

        return solve(root) != -1;
        
    }
};