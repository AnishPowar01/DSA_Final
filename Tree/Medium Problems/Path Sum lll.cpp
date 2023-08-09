class Solution {
public:
    unordered_map<long, int>mp;
    int count = 0;

    void solve(TreeNode* root, int target, long  sum)
    {
        if(root == NULL)
        {
        return ;
        }

        sum += root->val;

        if(sum == target)
        {
            count++;
        }


        if(mp.find(sum - target) != mp.end())
        {
            count += mp[sum - target];
        }

        mp[sum] ++;

        solve(root->left, target, sum);
        solve(root->right, target, sum);

        mp[sum]--;     // cause we are leaving the current path;

    }

    int pathSum(TreeNode* root, int targetSum) {

         solve(root, targetSum, 0);
         return count;
        
    }
};