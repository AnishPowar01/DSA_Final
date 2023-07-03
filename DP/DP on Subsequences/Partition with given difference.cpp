//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
      int mod = (int) 1e9 + 7;
      
      int solve(int index, vector<int>&nums, int target, vector<vector<int>>&dp)
      {
          if(index == 0)
          {
              if(nums[0] == 0 && target == 0)
              {
                  return 2;
              }
              
              if(target == 0 || nums[0] == target)
              {
                  return 1;
              }
              else
              {
                  return 0;
              }
          }
          
          if(dp[index][target]!=-1)
          {
              return dp[index][target] % mod;
          }
          
          
          int notTake = solve(index - 1, nums, target,dp);
          
          int take = 0;
          
          if(nums[index] <= target)
          {
              
              take = solve(index - 1, nums, target - nums[index],dp);
              
          }
          
          return dp[index][target] = (take + notTake) % mod;
      }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        int totalSum = 0;
        
        for(int i = 0; i<n; i++)
        {
            totalSum += arr[i];
        }
        
        
        if(totalSum - d < 0 || (totalSum - d)&2 !=0)
        {
            return 0;
        }
        
        int target = (totalSum - d)/2;
        
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        
        return solve(n-1, arr, target,dp) % mod;
    }
};


