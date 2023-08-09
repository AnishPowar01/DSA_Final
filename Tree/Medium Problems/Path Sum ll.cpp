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
    vector<vector<int>>ans;
    void solve(TreeNode* root ,int sum , int target, vector<int>&output)
    {
        if(root == NULL)
        {
            return ;
        }

        sum += root->val;
        output.push_back(root->val);

        if(!root->left && !root->right)
        {
            if(sum == target)
            {
                ans.push_back(output);
            }

            return;
        }

        vector<int>leftOutput = output;
        vector<int>rightOutput = output;

        solve(root->left, sum ,target,leftOutput);
        solve(root->right, sum ,target,rightOutput);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<int>output;

        solve(root,0, targetSum,output);

        return ans;
        
    }
};