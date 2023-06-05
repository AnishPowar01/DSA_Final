
 Approach : 1 

 Timecomplexity : 
 O(n) 

class Solution{

    public:
        vector<int> majorityElement(vector<int>&nums)
        {
            unordered_map<int,int>mp;

            for(auto it : nums)
            {
                mp[it]++;
            }


            vector<int>ans;

            for(auto it : mp)
            {
                if(it.second > nums.size()/3)
                {
                    ans.push_back(it.first);
                }
            }
            return ans;
        }
};




Approach 2 : Boyer-Moore Majority Vote algorithm
Time Complexity : O(n)



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        

        int n = nums.size();

        int num1 = -1;
        int num2 = -1;
        int count1 = 0;

        int count2 =0;


        for(int i = 0; i<n; i++)
        {
            if(nums[i]==num1)
            {
                count1++;
            }
            else if (nums[i]==num2)
            {
                count2++;
            }

            else if(count1==0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for(int i = 0; i<n; i++)
        {

            if(nums[i] == num1)
            {
                count1++;
            }
            else if(nums[i] == num2)
            {
                count2++;
            }

        }

        vector<int>ans;

       if(count1> n/3)
        {
            ans.push_back(num1);
        }

        if(count2> n/3)
        {
            ans.push_back(num2);
        }
        
        return ans;
        
    }
}; 