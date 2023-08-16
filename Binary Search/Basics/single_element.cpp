class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
        {
            return nums[0];
        }

        if(nums[0] != nums[1])
        {
            return nums[0];
        }

        if(nums[n-2] != nums[n-1])
        {
            return nums[n-1];
        }


        int start = 0;
        int end = n-1;


        while(start <= end)
        {
            int mid = start + (end -start)/2;

            if(nums[mid]!= nums[mid-1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }


            if(nums[mid]== nums[mid-1])
            {
                int leftCount = mid- start + 1;

                if(leftCount & 1)
                {
                    end = mid -2;
                }
                else
                {
                    start = mid + 1;
                }
            }else if (nums[mid] == nums[mid+1])
            {
                int rightCount = end - mid + 1;

                if(rightCount & 1)
                {
                    start = mid + 2;
                }
                else
                {
                    end = mid -1;
                }

            }
        }

        return -1;
        
    }
};