class Solution {
public:
     set<vector<int>> st;

     void solve(int index,vector<int>&nums,vector<int>store)
     {
         if(index == nums.size())
         {
             sort(store.begin(), store.end());
             st.insert(store);
             return;
         }


         store.push_back(nums[index]);

         solve(index + 1, nums, store);

         store.pop_back();

         solve(index + 1, nums, store);
     }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int>store;

        solve(0,nums,store);

        vector<vector<int>>ans;

        for(auto it : st)
        {
            ans.push_back(it);
        }

        return ans;

        
    }
};