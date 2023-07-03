// Tabulation
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    
	    vector<int>dp(n,0);
	    
	    dp[0] = arr[0];
	    
	    for(int i = 1; i<n; i++)
	    {
	        
	        int take = arr[i];
	        
	        if(i>1)
	        {
	            take+=dp[i-2];
	        }
	        
	        int notTake = dp[i-1];
	        
	        dp[i] = max(take,notTake);
	        
	    }
	    
	    return dp[n-1];
	}
};


// Recursion + Memoization

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int index, int *arr, vector<int>&dp)
	{
	    if(index == 0)
	    {
	        return arr[index];
	    }
	    
	    if(index < 0)
	    {
	        return 0;
	    }
	    
	    if(dp[index]!=-1)
	    {
	        return dp[index];
	    }
	    
	    int take = arr[index] + solve(index - 2 , arr,dp);
	    
	    int notTake = solve(index - 1, arr,dp);
	    
	    return dp[index] =  max(take, notTake);
	    
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    
	    vector<int>dp(n+1, -1);
	    
	    return solve(n-1, arr,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends