class Solution {
private:
    int dp[50001][2];
    int solve(vector<int>&prices, int day, bool buy)
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

        if(buy)                    // if buy is true.. then we have two option buy or notBuy
        {

            int buy = solve(prices, day+1, false) - prices[day];
            // if i buy on day one then i will call the function for selling it..
            // and profit is selling price - buying price..
            // here the function  solve(prices, day+1, false) - prices[i] will give us selling price
            // and prices[i] is buying price

            int not_buy = solve(prices, day+1, true);

            profit = max({profit,buy,not_buy});
        }
        //  selling case
        else
        {

            int sell = prices[day] + solve(prices, day+2, true);

            int not_sell = solve(prices, day+1, false);


            profit = max(profit,max(sell,not_sell));
        }


        return dp[day][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {

        bool buy = true;

        memset(dp,-1,sizeof(dp));

        return solve(prices, 0,buy);
        
    }
};