//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int helper(int index, int val[], int wt[], int bag_capacity, vector<vector<int>>&dp)
    {
        
        // base case
        
        if(index == 0)
        {
            if(wt[0] <= bag_capacity)
            {
                return val[0];
            }
            else
            {
                return 0;
                
            }
        }
        
        if(dp[index][bag_capacity]!=-1)
        {
            return dp[index][bag_capacity];
        }
        
        
        
        int notTake = helper(index - 1, val, wt, bag_capacity,dp);
        
        int take = INT_MIN;
        
        if(wt[index] <= bag_capacity)
        {
            take = val[index] +  helper(index - 1, val ,wt, bag_capacity - wt[index],dp);
        }
        
        return dp[index][bag_capacity] = max(notTake, take);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       
       vector<vector<int>>dp(n, vector<int>(W+1, -1));
       
       return helper(n-1, val, wt, W,dp);
    }
};

