//User function Template for C++

class Solution
{
    public:
    vector<vector<int>>ans;
    
    void solve(vector<int>&nums, int index, vector<int>store)
    {
        if(index >= nums.size())
        {
            
            ans.push_back(store);
            return;
        }
        
        
        // not take
        
        solve(nums,index+1,store);
        
        
        // take 
        
        store.push_back(nums[index]);
        solve(nums,index+1, store);
        // store.pop_back();
        
        
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        
        vector<int>store;
        
        solve(A, 0, store);
        
        sort(ans.begin(), ans.end());
        return ans;
        
        
    }
};