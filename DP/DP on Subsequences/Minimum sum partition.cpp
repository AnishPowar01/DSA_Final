/*
Using same logic of isSubset sum;;

we know that in last row of tabulation.. it wil clerly show that which subset is availabe or not


our goal is

s1 - s2 = d should be low  1)

s1 + s2 = sum;

s1 = sum - s2

(sum - s2) - s2 = d

so we can only find for s2 simple;;
add extra loop to detect min

equation 1 become


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    int totalSum = 0;
	    
	    for(int i = 0; i<n; i++)
	    {
	        totalSum += arr[i];
	    }
	    
	    vector<vector<bool>>dp(n, vector<bool>(totalSum + 1, 0));
	    
	    for(int i = 0; i<n; i++)
	    {
	        dp[i][0] = true;
	    }
	    
	    if(arr[0] <= totalSum)
	    {
	        dp[0][totalSum] = true;
	    }
	    
	    
	    for(int i = 1; i<n; i++)
	    {
	        
	        for(int j = 1; j<= totalSum; j++)
	        {
	            bool notTake = dp[i-1][j];
	            
	            bool take = false;
	            
	            if(arr[i] <= j)
	            {
	                take = dp[i-1][j - arr[i]];
	            }
	            
	            dp[i][j] = notTake || take;
	        }
	        
	    }
	    
	    
	    int mini = 1e9;
	    
	    for(int i = 0; i<=totalSum; i++)
	    {
	        if(dp[n-1][i] == true)
	        {
	            mini = min(mini, abs((totalSum - i) - i));
	        }
	        
	    }
	    
	    return mini;
	} 
};


