class Solution {
public:
    void solve(TreeNode* root, string &ans)
    {
        if(root == NULL)
        {
            return;
        }

        ans += to_string(root->val);

        if(root->left)
        {
            ans += "(";

            solve(root->left,ans);

            ans += ")";
        }
          if(root->right!=NULL)
        {
            // example number 2
            if(root->left == NULL)
            {
                ans += "()";
            }

            ans += "(";

            solve(root->right,ans);

            ans += ")";
        }


    }
    string tree2str(TreeNode* root) {
        string ans = "";

        solve(root ,ans);

        return ans;
        
    }
};