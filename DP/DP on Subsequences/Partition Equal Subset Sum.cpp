// Apply the same code of isSubset..
// we have to find two euqal subset.. but if we find only one subset we can easily find another by sum - subset1
// so we will check if there is any subset is present of target is equal to sum/2;



#include <bits/stdc++.h>
using namespace std;

// Recursive

class Solution{
public:
    int solve(int index, int arr[], int target)
    {
        if(index == 0)
        {
            return arr[0] == target;
        }
        
        if(target == 0)
        {
            return 1;
        }
        
        if(target < 0 || index < 0)
        {
            return 0;
        }
        
        int NotTake = solve(index - 1, arr, target);
        
        int take = 0;
        
        if(arr[index] <= target)
        {
            
            take = solve(index - 1 , arr, target - arr[index]);
            
        }
        
        
        return take || NotTake;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum = 0;
        
        for(int i = 0; i<N; i++)
        {
            sum += arr[i];
        }
        
        if(sum & 1)
        {
            return 0;
        }
        
        
        int target = sum /2;
        
        
        
        return solve(N-1, arr, target);
    }
};


// Recursion + Memo

class Solution {
public:
    bool isPossible(int i, vector<int>&nums, int target, vector<vector<int>>&dp)
    {
        if(i==0)
        {
            return nums[i] == target;
        }

        if(target == 0)
        {
            return 1;
        }

        if(target <0 || i<0)
        {
            return 0;
        }

        if(dp[i][target]!=-1)
        {
            return dp[i][target];
        }

        bool take = false;

        if(nums[i] <= target)
        {
            take = isPossible(i-1, nums, target - nums[i],dp);
        }

        bool NotTake = isPossible(i-1, nums, target,dp);


        return dp[i][target] = take || NotTake;
    }
    bool canPartition(vector<int>& nums) {

        int sum = 0; 

        for(int i = 0; i<nums.size(); i++)
        {
            sum += nums[i];
        }

        int n = nums.size();

        if(sum&1)
        {
            return false;
        }
         vector<vector<int>>dp(n,vector<int>(sum/2 + 1, -1));
        return isPossible(n-1, nums, sum/2,dp);
        
    }
};