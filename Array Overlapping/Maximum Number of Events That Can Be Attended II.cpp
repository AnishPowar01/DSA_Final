// can apply binary search instead of linear search

class Solution {
public:
    int solve(int index, vector<vector<int>>&nums, int k, vector<vector<int>>&dp)
    {
        if(index >= nums.size())
        {
            return 0;
        }

        if(k == 0)
        {
            return 0;
        }


        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }


        int notTake = solve(index+1, nums, k,dp);


        int startTime = nums[index][0];
        int EndTime = nums[index][1];
        int value = nums[index][2];

        int take = 0;

        int j = index+1;

        for(;j<nums.size(); j++)
        {
            if(nums[j][0] > EndTime)
            {
                break;
            }
        }


        take = value + solve(j, nums, k-1,dp);


        return dp[index][k] =  max(take, notTake);
    }
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end());

        int n = events.size();

        vector<vector<int>>dp(n, vector<int>(k+1, -1));

        return solve(0, events, k,dp);
    }
};