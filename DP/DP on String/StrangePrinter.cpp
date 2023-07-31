#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int start, int end, string &s, vector<vector<int>> &dp)
    {
        //  If start and end are the same character, only one step is required to print.
        if (start == end)
        {
            return 1;
        }

        //  If start is greater than end, the string is empty, so no steps required.
        if (start > end)
        {
            return 0;
        }

        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }

        // Find the index of the next character that is different from s[start].
        int index = start + 1;
        while (index <= end && s[start] == s[index])
        {
            index++;
        }

        // If all characters from start to end are the same, only one step is needed to print them all at once.
        if (index == end + 1)
        {
            return 1;
        }

        // Calculate the minimum steps required if we print the substring from start to 'index - 1'.
        int atOnce = 1 + solve(index, end, s, dp);

        // Now, behave greedily to find the optimal solution.
        int j = index;
        int mini = INT_MAX;

        // Iterate through each index j from 'index' to 'end'.
        // Whenever we find s[start] == s[j], it means we can group the substring from start to j as one unit.
        // We recursively find the optimal solution for the two separated substrings and take their sum.
        for (; j <= end; j++)
        {
            if (s[start] == s[j])
            {
                int greedy = solve(index, j - 1, s, dp) + solve(j, end, s, dp);
                mini = min(mini, greedy);
            }
        }

        return dp[start][end] = min(mini, atOnce);
    }

    int strangePrinter(string s)
    {
        int n = s.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(0, n - 1, s, dp);
    }
};

int main()
{
    string str = "aaaabaaaacc";

    // cout<<strangePrinter(s)<<"";

    Solution sol;

    int ans = sol.strangePrinter(str);

    cout << ans << "";

    return 0;
}