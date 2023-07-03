class Solution {
public:
// ask minimum coins required
    int solve(int index, vector<int>&nums, int target, vector<vector<int>>&dp)
    {
        if(index == 0)
        {
            if(target % nums[0] == 0)
            {
                return target / nums[0];
            }
            else
            {
            return 1e8;
            }

        }

        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }

        int notTake = solve(index - 1, nums, target, dp);

        int take = 1e8;

        if(nums[index] <= target)
        {

            take = 1 +  solve(index, nums, target - nums[index],dp);

        }

        return dp[index][target] = min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        int ans = solve(n-1, coins, amount,dp);

        return ans == 1e8 ? -1 : ans;
        
    }
};