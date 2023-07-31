class Solution {
private:
// Recur  + memo
int solve(int i , int j, string &s, string &rev,vector<vector<int>>&dp)
{
    if(i>=s.length() || j>=rev.length())
    {
        return 0;
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }


    if(s[i] == rev[j])
    {
        return  dp[i][j] = 1 + solve(i+1, j+1, s, rev,dp);
    }

    return dp[i][j] = max(solve(i+1, j ,s, rev,dp), solve(i, j+1, s, rev,dp));
}
int longestPalindromic(string &s)
{
    int n = s.length();

    string reva = s;

    vector<vector<int>>dp(n,vector<int>(n,-1));

    reverse(reva.begin(),reva.end());

    return solve(0,0,s,reva,dp);


}
public:
    int minInsertions(string s) {

        int n = s.length();
       

       return n - longestPalindromic(s);
     
    }

    
      // Bottom Up

    int minInsertions(string s) {

        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        string rev = s;
        reverse(s.begin(),s.end());


      

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

        return n -  dp[n][n];   
        
    }
};