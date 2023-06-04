class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        
        int maxi = INT_MIN;
        // We can solve this using kadane's Algorithm
        // logic of algo is that -> if at any point sum<0 then reinitialised the sum to zero and again calculate the sum;


        for(int  i = 0; i<nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, sum);

            if(sum<0)
            {
                sum = 0;
            }
        }

        return maxi;
        
    }
};