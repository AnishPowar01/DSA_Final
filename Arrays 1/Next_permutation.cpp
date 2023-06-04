class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // traverse from back and find the break point (arr[i]<arr[i+1])

         int index = -1;
        for(int i = n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                index = i;
                break;
            }
        }

        // we we don't find any break point then reverse the given input that would be our ans

        if(index == -1)
        {
            reverse(nums.begin(), nums.end());
            return ;
        }


        // if we found the break point .. Now we have to arrange the array such way that the resultant array will be slighlty greater than given array


        // traverse again from back and check the element which is greater than arr[index]

        for(int i = n-1; i>index; i--)
        {
            if(nums[i] > nums[index])
            {
                swap(nums[i],nums[index]);
                break;   // beacuse we want a smallest element which is greater than arr[index]
            }
        }


        // now either sort the array from index or just reverse it .. beacause we know that the array till the break point is in increasing fashion.

        reverse(nums.begin()+index+1, nums.end());
        
    }
};