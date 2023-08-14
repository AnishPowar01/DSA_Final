class Solution {
public:
    int n;
    int solve(int index, bool  buy, vector<int>&nums,vector<vector<int>>&dp)
    {
        if(index >= nums.size())
        {
            return 0;
        }

        int profit = 0;

        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }


        // buy

        if(buy)
        {
            int buyIt = solve(index+1, false, nums,dp) - nums[index];

            int not_buy = solve(index+1, true, nums,dp);


            profit = max({profit,buyIt, not_buy});
        }// sell
        else
        {
            int sell = nums[index] + solve(index+1, true, nums,dp);

            int not_sell =  solve(index+1, false, nums,dp);

            profit = max({profit, sell, not_sell});
        }

        return dp[index][buy] = profit;

    }
    int maxProfit(vector<int>& prices) {

      n = prices.size();
    //   memset(dp,-1,sizeof(dp));

    vector<vector<int>>dp(n, vector<int>(2, -1));
        
        bool buy = true;

        return solve(0, buy, prices,dp);
        
    }
};