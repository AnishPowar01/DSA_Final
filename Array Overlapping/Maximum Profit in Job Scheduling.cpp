class Solution {
public:
    int solve(int index, vector<vector<int>>&nums, vector<int>&dp)
    {
        if(index>= nums.size())
        {
            return 0;
        }

        if(dp[index]!=-1)
        {
            return dp[index];
        }


        int notTake = solve(index+1, nums,dp);

        int startTime = nums[index][0];
        int endTime = nums[index][1];
        int  value = nums[index][2];

        int take  = 0;
        int i = index+1;

        // binary search can be applied

        for(; i<nums.size(); i++)
        {

            if(nums[i][0] >= nums[index][1])
            {
                break;
            }
        }


        take = value + solve(i, nums,dp);


        return dp[index] =  max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        vector<vector<int>>nums;

        for(int i = 0; i<startTime.size(); i++)
        {
            vector<int>level;

            level.push_back(startTime[i]);
            level.push_back(endTime[i]);
            level.push_back(profit[i]);
            nums.push_back(level);
        }

        sort(nums.begin(), nums.end());
 
        vector<int>dp(nums.size(), -1);

        return solve(0, nums, dp);
        
    }
};