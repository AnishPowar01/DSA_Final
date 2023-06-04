// The problem was posed with three colors, here `0′, `1′ and `2′. The array is divided into four sections: 
// arr[1] to arr[low – 1]
// arr[low] to arr[mid – 1]
// arr[mid] to arr[high – 1]
// arr[high] to arr[n]
// If the ith element is 0 then swap the element to the low range.
// Similarly, if the element is 1 then keep it as it is.
// If the element is 2 then swap it with an element in high range.

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // use Dutch National Flag algorithm

        int n = nums.size();

        int start = 0 ;
        int mid = 0;
        int end  = n-1;


        while(mid <= end)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid],nums[start]);
                mid++;
                start++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[end]);
                end--;
            }
        }
        
    }
};