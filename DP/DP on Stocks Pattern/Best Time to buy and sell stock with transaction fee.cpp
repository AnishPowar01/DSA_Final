class Solution {
public:
    int dp[50001][2];
    int solve(vector<int>&prices, int day, int fee, bool buy)
    {
        if(day >= prices.size())
        {
            return 0;
        }

        if(dp[day][buy]!=-1)
        {
            return dp[day][buy];
        }

        int profit = INT_MIN;

        if(buy)
        {
            int take = solve(prices, day+1, fee, false) - prices[day];
            int not_buy = solve(prices, day+1, fee, true);

            profit = max({profit, take, not_buy});
        }

        else
        {
            int sell =  prices[day] + solve(prices,day+1, fee, true) - fee;
            int not_sell = solve(prices, day+1, fee, false);

            profit = max({profit,sell, not_sell});


        }

        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {

        bool buy = true;

        memset(dp,-1,sizeof(dp));

        return solve(prices, 0, fee, buy);
    
    }
};