class Solution {
public:
    int solve(int i, int j,  vector<vector<int>>&nums, vector<vector<int>>&dp)
    {
        if(j<0 || j >= nums[0].size() || i>= nums.size())
        {
            return 1e8;
        }

        if(i== nums.size()-1)
        {
            return nums[i][j];
        }

        if(dp[i][j]!=INT_MAX)
        {
            return dp[i][j];
        }


        // Three Directions

        int bottomLeft = nums[i][j] + solve(i+1, j-1, nums,dp); 
        int bottomRight = nums[i][j] + solve(i+1, j, nums,dp);
        int down =  nums[i][j] + solve(i+1, j+1, nums,dp);

        return dp[i][j] =  min({bottomLeft,bottomRight,down});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>>dp(n+1, vector<int>(m+1,INT_MAX));


        int ans = INT_MAX;

        for(int j = 0; j<m; j++)
        {
            ans = min(ans, solve(0, j,matrix,dp));
        }


        return ans;

    }
};