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
    int leftSum = 0;
    bool isLeaf(TreeNode* root)
    {
        if(root==NULL)
        return false;

        if(root->left==NULL && root->right==NULL)
        return true;


        return false;
    }
    void helper(TreeNode* root)
    {
        if(root==NULL) return;

        if(isLeaf(root->left))
         leftSum+= root->left->val;

         helper(root->left);
         helper(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {

        helper(root);

        return leftSum;
        
    }
};