// MERGE SORT IN-PLACE 
// Time Complexity : O(nlogn)
// space Complexity : O(logn)
class Solution {
    void mergeTwoArraysInPlace(vector<int>&arr, int start, int end)
    {
        // find the length;
        int length = end - start + 1;

        int gap = (length / 2 ) + (length % 2);

        while(gap > 0)
        {
            int index1 = start;
            int index2 = start + gap;

            while(index2 <=end)
            {
                if(arr[index1] > arr[index2])
                {
                    swap(arr[index1] , arr[index2]);
                }

                index1++;
                index2++;
            }

            gap = (gap <= 1) ? 0 : (gap/2) + (gap % 2);
        }
    }
public:
    void mergeSort(vector<int>&nums, int start, int end)
    {
        if(start >= end)
        {
            return;
        }

        int mid = start + (end - start)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);

        mergeTwoArraysInPlace(nums,start, end);

        
    }
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        mergeSort(nums, 0, n-1);

        return nums;
        
    }
};