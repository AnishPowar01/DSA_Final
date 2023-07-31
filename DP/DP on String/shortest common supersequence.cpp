
// str1 =
// "aggtab"
// str2 =
// "gxtxayb"
// Table (dp[i][j]):
                //   g   x   t   x   a   y   b
        //        0   1   2   3   4   5   6   7 
        //    +---+---+---+---+---+---+---+---+
        // 0  | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
        //    +---+---+---+---+---+---+---+---+
        //a 1  | 0 | 0 | 0 | 0 | 0 | 1 | 1 | 1 |
        //    +---+---+---+---+---+---+---+---+
        //g 2  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
        //    +---+---+---+---+---+---+---+---+
        //g 3  | 0 | 1 | 1 | 1 | 1 | 1 | 1 | 1 |
        //    +---+---+---+---+---+---+---+---+
        //t 4  | 0 | 1 | 1 | 2 | 2 | 2 | 2 | 2 |
        //    +---+---+---+---+---+---+---+---+
        //a 5  | 0 | 1 | 1 | 2 | 2 | 3 | 3 | 3 |
        //    +---+---+---+---+---+---+---+---+
        //b 6  | 0 | 1 | 1 | 2 | 2 | 3 | 3 | 4 |
        //    +---+---+---+---+---+---+---+---+

// ans :- aggxtxayb

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.length();
        int m = str2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // base cases for LCS
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for(int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        // Populate the table using LCS algorithm
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1]; // If characters match, extend the LCS by 1.
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // If characters don't match, choose the maximum LCS so far.
                }
            }
        }

        int i = n;
        int j = m;

        string ans = "";

        // Reconstruct the shortest common supersequence using LCS table
        while(i > 0 && j > 0) {

            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1]; // Include the matched character in the supersequence.
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                ans += str1[i-1]; // Include the character from str1 as it contributes to LCS.
                i--;
            } else {
                ans += str2[j-1]; // Include the character from str2 as it contributes to LCS.
                j--;
            }
        }

        // Add remaining characters of str1 and str2 to the supersequence.
        while(i > 0) {
            ans += str1[i-1];
            i--;
        }

        while(j > 0) {
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end()); // Reverse the supersequence to get the correct order.
        return ans;
    }
};
