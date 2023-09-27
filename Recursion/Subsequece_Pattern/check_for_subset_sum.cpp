bool solve(int index, vector<int>&nums, int k, vector<vector<int>>&dp)
{
    if(index >= nums.size())
    {
        if(k==0)
        {
            return 1;
        }

        return 0;
    }

    if(dp[index][k] != -1)
    {
        return dp[index][k];
    }


    bool notTake = solve(index+1, nums, k,dp);

    bool take = 0;

    if (nums[index] <= k) {
        take = solve(index + 1, nums, k - nums[index],dp);
    }

    return dp[index][k] = take ||  notTake;
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here

    vector<vector<int>>dp(n+1, vector<int>(k+1, -1));

    return solve(0, a, k, dp);
}