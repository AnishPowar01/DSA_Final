// Approach 1 : Brute Force
// Time Complexity : O(n^4)  TLE
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        set<vector<int>>st;

        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                for(int k = j+1; k<n; k++)
                {
                    for(int l = k+1; l<n; l++)
                    {

                        long long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];


                        if(sum == target)
                        {
                            vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};

                            sort(temp.begin(),temp.end());

                            st.insert(temp);
                        }

                    }
                }
            }
        }

        vector<vector<int>>ans(st.begin(), st.end());

        return ans;
        
    }
};



// Approach 2 : Better 
// Time Complexity : O(N^3) * logm

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        set<vector<int>>st;

        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                set<long long> hashSet;


                for(int k = j+1; k<n; k++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];

                    long long remaining_sum = target - (sum);


                    if(hashSet.find(remaining_sum)!=hashSet.end())
                    {
                        vector<int>temp = {nums[i],nums[j],nums[k],(int)(remaining_sum)};

                        sort(temp.begin(),temp.end());

                        st.insert(temp);
            
                    }


                    hashSet.insert(nums[k]);
                    
                }
            }
        }

        vector<vector<int>>ans(st.begin(), st.end());

        return ans;
        
    }
};


// Approach 3 : Optimal 
// Time_Complexity : O(n^3)


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}