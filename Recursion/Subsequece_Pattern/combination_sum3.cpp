class Solution {
public:
    vector<vector<int>>ans;
    void solve(int index, vector<int>&nums, vector<int>temp, int k, int n)
    {

        if(index >= nums.size())
        {
            if(n == 0 && temp.size() == k)
            {
                ans.push_back(temp);
            }
            return ;
        }
        

        if(nums[index] <= n)
        {
            temp.push_back(nums[index]);
            solve(index+1, nums, temp, k, n - nums[index]);
            temp.pop_back();
        }
          

        solve(index+1, nums, temp, k, n);

        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<int>temp;

        solve(0, nums, temp, k,n);

        return ans;
    }
};