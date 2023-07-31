// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

// In one step, you can delete exactly one character in either string.


// Example 1:

// Input: word1 = "sea", word2 = "eat"
// Output: 2
// Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

class Solution {
public:
    int LCS(int i ,  int j, string &s, string &d, vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }


        if(s[i] == d[j])
        {
            return dp[i][j] =  1 + LCS(i-1, j-1, s, d,dp);
        }

        return dp[i][j] =  max(LCS(i-1, j ,s, d,dp), LCS(i, j-1, s,d,dp));
    }
    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n, vector<int>(m, -1));

        int ans = n+m;

        return ans - 2*(LCS(n-1, m-1, word1, word2,dp));
        
    }
};