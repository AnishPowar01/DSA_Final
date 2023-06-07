

// Approach 1 : Brute
// time_complexity : O(n^2)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    return {i,j};
                }
            }
        }
        
        return {-1,-1};
        
    }
};



// Approach 2 : Two Pointer Approach (Better)
// Complexity :  O(n) + O(n log n) + O(n) = O(n log n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<pair<int,int>> v;
        
        for(int i = 0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int start = 0;
        int end = n-1;
       
        
        while(start<end)
        {
            int sum = v[start].first+v[end].first;
            
            if(sum == target)
            {
                return {v[start].second,v[end].second};
            }
            
            else if (sum>target)
            {
                end--;
            }
            
            else
            {
                start++;
            }
        }
        
        return {-1,-1};
        
    }
};


// Approach 3 : Optimal
// Time Complexity : O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


        unordered_map<int,int>mp;


        for(int i = 0; i<nums.size(); i++)
        {
            int num = nums[i];

            int remaining_sum = target - num;


            if(mp.find(remaining_sum)!=mp.end())
            {
                return {mp[remaining_sum],i};
            }

            mp[num] = i;
        }
        

        return {-1,-1};
    }
};