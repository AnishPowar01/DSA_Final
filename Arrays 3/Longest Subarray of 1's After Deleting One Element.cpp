// TC : O(N^2)

class Solution {
public:
    int n;
    int findAnother(vector<int>&nums, int skip_index)
    {
        int maxLength = 0;
        int counter = 0;

        for(int i = 0; i<n; i++)
        {
            if(i == skip_index)
            {
                continue;
            }

            if(nums[i] == 1)
            {
                counter++;
                maxLength = max(maxLength,counter);
            }
            else
            {
                counter = 0;
            }
        }

        return maxLength;
    }
    int longestSubarray(vector<int>& nums) {

        int result = 0;
        n = nums.size();

        int zeroCounter = 0;

        for(int i = 0; i<n;i++)
        {
            if(nums[i] == 0)
            {
                zeroCounter++;
                result = max(result, findAnother(nums, i));
            }
        }

        if(zeroCounter == 0)
        {
            return n-1;
        }

        return result;
        
    }
};