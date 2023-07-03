
#include<bits/stdc++.h>
using namespace std;

// Recursion and Memo
class Solution
{
    public:
    
    const long MOD = 1e9 + 7;
    int solve(int n , vector<int>&dp)
    {
        if(n<=3)
        {
            return n;
        }
        
        if(n<0)
        {
            return n;
        }
        
        if(dp[n]!=-1)
        {
            return dp[n] % MOD;
        }
        
        
        return dp[n] = solve(n-1,dp) % MOD + solve(n-2,dp) % MOD;
        
    }
    int countWays(int n)
    {
        // your code here
        
        vector<int>dp(n+1, -1);
        
        return solve(n, dp) % MOD;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}




// Tabulation
class Solution {
public:
    int dp[50] = {0};
    int climbStairs(int n) {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2]; 
        }

        return dp[n];
        
    }
};

// Space Optimized
class Solution {
public:
    int dp[50] = {0};
    int climbStairs(int n) {
        
        
        int prev1 = 1;
        int prev = 1;

        for(int i = 2; i<=n; i++)
        {
            int curri = prev + prev1;
            prev1 = prev;
            prev = curri;
        }

        return prev;
        
    }
};