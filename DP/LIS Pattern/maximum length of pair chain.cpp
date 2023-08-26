

// Solution 1: Recursive with Memoization
// Time complexity : O(n^2);
// Space Complexity : O(n^2);
class Solution {
public:
    int solve(int index, int prev, vector<vector<int>>& nums, vector<vector<int>>& dp) {
        if (index >= nums.size()) {
            return 0;
        }

        if (dp[index][prev + 1] != -1) {
            return dp[index][prev + 1];
        }

        int not_take = solve(index + 1, prev, nums, dp);

        int take = 0;
        if (prev == -1 || nums[prev][1] < nums[index][0]) {
            take = 1 + solve(index + 1, index, nums, dp);
        }

        return dp[index][prev + 1] = max(take, not_take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));
        return solve(0, -1, pairs, dp);
    }
};


// Solution 2: Tabulation (Bottom-up DP)
// Time complexity : O(n^2);
// Space Complexity : O(n^2);
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int prev = index - 1; prev >= -1; prev--) {
                int notTake = dp[index + 1][prev + 1];

                int take = 0;
                if (prev == -1 || pairs[prev][1] < pairs[index][0]) {
                    take = 1 + dp[index + 1][index + 1];
                }

                dp[index][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][-1 + 1];
    }
};


// Solution 3: Space-Optimized Tabulation
// Time complexity : O(n^2);
// Space Complexity : O(n);
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (pairs[prev][1] < pairs[i][0] && dp[i] < 1 + dp[prev]) {
                    dp[i] = dp[prev] + 1;
                    maxi = max(maxi, dp[i]);
                }
            }
        }

        return maxi;
    }
};
