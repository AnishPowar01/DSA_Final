class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;


        while(start < end)
        {
            int mid = start + (end - start)/2;


            if(nums[mid] < nums[mid+1])
            {
                // nums[mid] can never be an possible candidate for peak element.

                start = mid + 1;
            }
            else if(nums[mid] > nums[mid+1])
            {
                // here nums[mid] can be a possible ans., so doest not ignore it.

                end = mid;
            }
        }

        return start;
        
    }
};