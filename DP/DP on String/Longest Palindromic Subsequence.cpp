class Solution {
public:
    // recur + memo
    int helper(string &s, string &rev, int i , int j, vector<vector<int>> &dp)
    {
        if(i>=s.length() || j>=rev.length())
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }


        if(s[i]==rev[j])
        {
            return dp[i][j] = 1 + helper(s,rev,i+1,j+1,dp);
        }

        return dp[i][j] =  max(helper(s,rev,i+1,j,dp),helper(s,rev,i,j+1,dp));
    }
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        string rev = s;
        reverse(s.begin(),s.end());

        // return  helper(s,rev,0,0,dp);

        // bottom up


        // base conditions
        for(int i = 0; i<=n; i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 0; j<=n; j++)
        {
            dp[0][j] = 0;
        }


        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=n; j++)
            {
                if(s[i-1] == rev[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];

    }
};