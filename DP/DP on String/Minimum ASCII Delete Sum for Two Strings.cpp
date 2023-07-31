class Solution {
public:
// use lcs to find common sum
    int LCS(int i, int j , string &s1, string &s2, vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        if(s1[i] == s2[j])
        {
            return dp[i][j] = s1[i] + LCS(i-1, j-1, s1, s2,dp);
        }

        return dp[i][j] =  max(LCS(i-1, j, s1, s2,dp), LCS(i, j-1, s1, s2,dp));
        
    }
    int minimumDeleteSum(string s1, string s2) {

        int sum1 = 0;
        int sum2 = 0;

        int  n = s1.length();
        int m = s2.length();

        for(auto it : s1)
        {
            sum1 += it;
        }

        for(auto it : s2)
        {
            sum2 += it;
        }

        // delete the common sum from total sum of two string
        // similar pattern like leetcode 583

        vector<vector<int>>dp(n, vector<int>(m, -1));

        return sum1+sum2 - 2 * LCS(n-1, m-1,s1,s2,dp);
        
    }
};
