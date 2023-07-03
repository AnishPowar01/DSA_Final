class Solution {
public:
    int solve(int i,  int j ,vector<vector<int>>&nums ,int n, vector<vector<int>>&dp)
    {
        if(i == n-1)
        {
            return nums[n-1][j];
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }


        int down = nums[i][j] + solve(i+1, j, nums, n,dp);
        int diagonal = nums[i][j] + solve(i+1, j+1, nums, n,dp);

        return  dp[i][j] = min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        int m = triangle[0].size();
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        // return solve(0,0, triangle, n, dp);


        for(int j = 0; j<n; j++)
        {
            dp[n-1][j] = triangle[n-1][j];
        }


        // bottom up;

        for(int i = n-2; i>=0; i--)
        {
            for(int j = i; j>=0 ; j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,diagonal);
            }
        }

        return dp[0][0];
        
    }
};