class Solution {
public:
    int solve(int i, int j , string&s1, string&s2, vector<vector<int>>&dp)
    {
        if(j<0)
        {
            return 1;
        }

        if(i < 0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(s1[i] == s2[j])
        {
            return dp[i][j] = (solve(i-1, j-1, s1 , s2,dp) + solve(i-1, j, s1, s2,dp));
        }

        return dp[i][j] =  solve(i-1, j, s1, s2,dp);
    }
    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<double>>dp(n+1,vector<double>(m+1, 0));
        // return solve(n-1, m-1, s, t,dp);

        for(int i = 0; i<=n; i++)
        {
            dp[i][0] = 1;
        }

        for(int j = 1; j<=m; j++)
        {
            dp[0][j] = 0;
        }

        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return (int)dp[n][m];
        
    }
};