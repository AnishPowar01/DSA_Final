class Solution {
public:
    int FindStart(vector<int>&nums, int target,int ans,bool IsStart)
    {
        int start = 0;
        int end = nums.size()-1;

        while(start<=end)
        {
            int mid = start + (end-start)/2;

            if(target<nums[mid])
            {
               
                   end = mid-1;
            }
            else if(target>nums[mid])
            {
              start = mid+1;
            }

            else
            {
                 ans = mid;
                if(IsStart)
                {
                  end = mid-1;
                }
                else
                {
                    start = mid+1;
                }
            }
        }

        return ans;
    }
   
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> result;
        int ans = -1;

        int StartPos = FindStart(nums,target,ans,true);
        int EndPos = FindStart(nums,target,ans,false);

        result.push_back(StartPos);
        result.push_back(EndPos);

        return result;
    }
};