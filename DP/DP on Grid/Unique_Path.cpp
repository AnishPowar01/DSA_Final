class Solution {
private:

    int helper(int i, int j, int m,  int n, vector<vector<int>>&dp)
    {
        if(i == m && j == n)
        {
            return 1;
        }

        if(i>m || j>n)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }


        int right = helper(i,j+1,m,n,dp);
        int bottom = helper(i+1,j,m,n,dp);

        return dp[i][j] =  right + bottom;
    }

public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return helper(0,0,m-1,n-1,dp);
        
    }
};