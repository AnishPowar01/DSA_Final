class Solution {
public:
    vector<pair<int,int>>operations = {{100,0}, {75,25}, {50,50}, {25,75}};
    double solve(double a, double b, vector<vector<double>>&dp)
    {
        // if both are zero then return the half  the probability.
        if(a<=0 && b<=0)
        {
            return 0.5;
        }


        if(a<=0)
        {
            return 1.0;
        }

        // we have to just find the probability of a being 0; thats why we are returning 0 here;
        if(b<=0)
        {
            return 0.0;
        }

        if(dp[a][b]!=-1)
        {
            return dp[a][b];
        }

        double prob = 0.0;

        for(auto &it : operations)
        {
            double first = it.first;
            double second = it.second;

            prob += solve(a-first, b - second,dp); 
        }

        return dp[a][b] =  0.25 * prob;

    }
    double soupServings(int n) {
        // if the value of n is increasing then the probability of A being zero will be increased;

        if(n>= 5000)
        {
            return 1.0;
        }

        vector<vector<double>>dp(n+1, vector<double>(n+1,-1));
        return solve(n,n,dp);
       
    }
};