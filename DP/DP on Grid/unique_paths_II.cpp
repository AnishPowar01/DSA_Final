class Solution {
private:
    int n;
    int m;

    int helper(int i , int j, vector<vector<int>>&nums,vector<vector<int>>&dp)
    {
        if(i<n && j<m && nums[i][j]==1)
        {
            return 0;
        }

        if(i == n-1 && j == m-1 && nums[i][j] != 1)
        {
            return 1;

        }

        if(i>n-1 || j>m-1)
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int right = helper(i,j+1,nums,dp);
        int bottom = helper(i+1,j,nums,dp);


        return dp[i][j] =  right + bottom;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));



        return helper(0,0,obstacleGrid,dp);
        
    }
};