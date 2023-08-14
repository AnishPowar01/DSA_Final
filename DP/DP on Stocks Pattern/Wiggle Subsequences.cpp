// A wiggle sequence is a sequence where the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

// For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences (6, -3, 5, -7, 3) alternate between positive and negative.
// In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. The first is not because its first two differences are positive, and the second is not because its last difference is zero.
// A subsequence is obtained by deleting some elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.

// Given an integer array nums, return the length of the longest wiggle subsequence of nums.

class Solution {
public:
    int solve(int index, vector<int>&nums, bool isPositive, vector<vector<int>>&dp)
    {
        if(index == nums.size()-1)
        {
            return 1;
        }

        if(dp[index][isPositive]!=-1)
        {
            return dp[index][isPositive];
        }

        int maxi = 0;

        if(isPositive)
        {
            int take = 0;
            int notTake = 0;

            if(nums[index+1] > nums[index])
            {
                take = 1 + solve(index+1, nums, false,dp);
            }
            else
            {
                notTake = solve(index+1, nums, true,dp);
            }

            maxi = max({maxi,take, notTake});
        }
        else
        {
            int take = 0;
            int notTake = 0;

            if(nums[index+1] < nums[index])
            {

                take = 1 + solve(index+1, nums, true,dp);

            }
            else
            {
                notTake = solve(index+1, nums, false,dp);
            }

            maxi = max({maxi, take, notTake});
        }

        return dp[index][isPositive] =  maxi;
    }
    int wiggleMaxLength(vector<int>& nums) {

        int n = nums.size();

        // stock problem like pattern.. 

        vector<vector<int>>dp1(n, vector<int>(2, -1));
        // first as positive
        int ans = solve(0, nums, true,dp1);
        
         vector<vector<int>>dp2(n, vector<int>(2, -1));
        // first as negative
        int maxi = max(ans, solve(0,nums, false,dp2));

        return maxi;   
    }
};