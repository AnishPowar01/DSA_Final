class Solution {
public:
    // Asked the number of ways to make the given target
    int solve(int index, vector<int>&nums, int target, vector<vector<int>>&dp)
    {
        if(index == 0)
        {
            return (target % nums[0] == 0);
        }

        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }

        int notTake = solve(index - 1, nums, target, dp);

        int take = 0;

        if(nums[index] <= target)
        {

            take = solve(index, nums, target - nums[index],dp);

        }

        return dp[index][target] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        return  solve(n-1, coins, amount,dp);


        
    }
};