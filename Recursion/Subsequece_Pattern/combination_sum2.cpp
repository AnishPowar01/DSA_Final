class Solution {
public:
    void solve(int index, vector<int>&nums, vector<vector<int>>&ans, vector<int>ds, int target)
    {
            if(target == 0)
            {
                ans.push_back(ds);
                return;
            }

        
        for(int i = index; i<nums.size(); i++)
        {

            if(i > index && nums[i-1] == nums[i]) continue;

            if(nums[i] > target) break;


            ds.push_back(nums[i]);
            solve(i+1, nums, ans, ds, target - nums[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>>ans;
        vector<int>ds;

        solve(0, candidates, ans ,ds, target);

        return ans;
        
    }
};