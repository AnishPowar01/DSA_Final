class Solution {
public:
    int n;
    int solve(int index, bool  buy, vector<int>&nums,vector<vector<vector<int>>>&dp,int limit)
    {
        if(index >= nums.size())
        {
            return 0;
        }

        if(limit == 0)
        {
            return 0;
        }

        int profit = 0;

        if(dp[index][buy][limit]!=-1)
        {
            return dp[index][buy][limit];
        }


        // buy

        if(buy)
        {
            int buyIt = solve(index+1, false, nums,dp,limit) - nums[index];

            int not_buy = solve(index+1, true, nums,dp,limit);


            profit = max({profit,buyIt, not_buy});
        }// sell
        else
        {
            int sell = nums[index] + solve(index+1, true, nums,dp, limit-1);

            int not_sell =  solve(index+1, false, nums,dp,limit);

            profit = max({profit, sell, not_sell});
        }

        return dp[index][buy][limit] = profit;

    }
    int maxProfit(vector<int>& prices) {

      n = prices.size();
    //   memset(dp,-1,sizeof(dp));

     vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        
        bool buy = true;

        return solve(0, buy, prices,dp,2);
        
    }
};