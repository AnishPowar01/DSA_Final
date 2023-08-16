class Solution {
public:
    int findMin(vector<int>& nums) {

        int ans = INT_MAX;
        int start = 0;
        int end = nums.size()-1;


        while(start <= end)
        {
            int mid = start + (end - start)/2;

            // if already sorted.. no rotation
            if(nums[start] <= nums[end])
            {
                ans = min(ans, nums[start]);
            }


            // if left half is sorted

            if(nums[start] <= nums[mid])
            {
                // store the minimum and eliminate the left half;

                ans = min(ans, nums[start]);
                start = mid + 1;
            }
            else
            {
                // store the minimum and eliminate the right half;
                ans = min(ans, nums[mid]);

                end = mid -1;
            }
        }

        return ans;
        
    }
};