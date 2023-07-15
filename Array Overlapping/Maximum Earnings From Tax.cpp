class Solution {
public:
long long dp[(int)1e5];  
    int findIT(int start, vector<vector<int>>&nums, int toFind)
    {
        int end = nums.size() -1;

        int ans = -1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(nums[mid][0] >= toFind)
            {
                ans = mid;

                end = mid -1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
    long long solve(int index, int n , vector<vector<int>>&nums)
    {
        if(index>= nums.size())
        {
            return 0;
        }

        // if(nums[index][0] > n || nums[index][1] > n)
        // {
        //     return 0;
        // }

        if(dp[index]!=-1)
        {
            return dp[index];
        }


        long long notTake = solve(index+1, n, nums);

        long long startPoint = nums[index][0];
        long long endPoint = nums[index][1];
        long long  value = endPoint - startPoint +  nums[index][2];

        long long take = 0;

        int j = findIT(index+1, nums, nums[index][1]);
        // giving tle aftyer optimization also..
        // use bunary search to find the index...
        // for(;j<nums.size(); j++)
        // {
        //     // if(nums[j][0] >= nums[index][1] && nums[j][0]<=n)
        //     if(nums[j][0] >= nums[index][1])
        //     {
        //         break;
        //     }
        // }

        take = value + solve(j, n, nums);


        return dp[index] =  max(take, notTake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {

        sort(rides.begin(), rides.end());


        memset(dp,-1,sizeof dp);
        return solve(0, n, rides);
        
    }
};