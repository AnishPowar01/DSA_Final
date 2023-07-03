// Similar concept of max sum without adjacent

class Solution {
public:
    int n;
    int dp[101];
    int helper(int i , vector<int>&nums)
    {
        if(i>=nums.size())
        {
            return 0;
        }

        if(dp[i]!=-1)
        {
            return dp[i];
        }


        int take = 0;

        take = nums[i] + helper(i+2, nums);

        int notTake = helper(i+1, nums);


        return dp[i] = max(take,notTake);
    }
    int rob(vector<int>& nums) {
        n = nums.size();

        memset(dp,-1,sizeof(dp));


        return helper(0,nums);
        
    }
};