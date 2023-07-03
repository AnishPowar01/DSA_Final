class Solution {
  public:
//   Recursion + Memo
    int helper(vector<int>& h, int i, vector<int>&dp)
    {
        if(i==0) return 0;
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        int left = helper(h,i-1,dp) + abs(h[i] - h[i-1]);
        
        int right = INT_MAX;
        
        if(i>1)
        {
            right = helper(h,i-2,dp) + abs(h[i]-h[i-2]);
            
        }
        
        return dp[i] = min(left,right);
    }

    // Tabulation
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        vector<int>dp(n,0);
        
        dp[0] = 0;
        
        for(int i = 1; i<n; i++)
        {
            int firstStep = dp[i-1] + abs(height[i]-height[i-1]);
            
            int secondStep = INT_MAX;
            
            if(i>1)
            {
                secondStep = dp[i-2] + abs(height[i]-height[i-2]);
            }
            
            dp[i] = min(firstStep, secondStep);
            
        }
        
        
        return dp[n-1];
        
        
        
    }
};