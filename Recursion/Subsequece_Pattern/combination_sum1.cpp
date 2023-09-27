class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums, int index, int target, vector<int>&store)
    {
        if(index >= nums.size())
        {
            if(target == 0)
            {
                ans.push_back(store);
            }

            return;
        }

        // take

        if(nums[index] <= target)
        {
            store.push_back(nums[index]);

            solve(nums,index, target-nums[index], store);

            store.pop_back();
        }

        solve(nums, index +1 , target, store);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       

       vector<int>store;

       solve(candidates, 0, target, store);


       return ans;

        
    }
};