class Solution {
public:
    void helper(TreeNode* root, vector<int>&ans)
    {
        if(root==NULL) return;

        if(root->left!=NULL)
        {
            helper(root->left,ans);
        }

        ans.push_back(root->val);

          if(root->right!=NULL)
        {
            helper(root->right,ans);
        }
    }
    int getMinimumDifference(TreeNode* root) {

        vector<int> ans;

        helper(root,ans);

        int mini = INT_MAX;

        for(int i = 0; i<ans.size()-1; i++)
        {
            mini = min(mini,abs(ans[i]-ans[i+1]));
        }


        return mini;
        
    }
};