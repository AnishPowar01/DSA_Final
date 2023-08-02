class Solution {
public:
    void solve(TreeNode* root, unordered_map<int,int>&mp)
    {
        if(root == NULL)
        {
            return ;
        }
        else 
        {
            mp[root->val]++;
        }

        solve(root->left, mp);
        solve(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;

        solve(root, mp);
        vector<int>result; 

        int maxi = INT_MIN;

        for(auto it : mp)
        {
            if(it.second > maxi)
            {
                maxi = it.second;
            }
        }

        for(auto it : mp)
        {
            if(it.second == maxi)
            {
                result.push_back(it.first);
            }
        }

        return result;
    
    }
};