# Approach 1

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        for(auto it : nums)
        {
            mp[it]++;
        }


        for(auto it : mp)
        {
            if(it.second > (n/2))
            {

                return it.first;

            }
        }

        return 0;
        
    }
};


# Approach 2

class Solution{

     public:
    int majorityElement(vector<int>& nums) {

        int count = 0;
        int element = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            if(count == 0)
            {
                element = nums[i];
            }
            
                if(nums[i] == element)
                {
                    count++;
                }
                else
                {
                    count --;
                }
            
        }


        count = 0;


        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == element)
            {
                count++;
            }
        }


        if(count > (nums.size()/2))
        {
            return element;
        }

        return 0;
    }

};