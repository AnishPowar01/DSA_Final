#include <bits/stdc++.h>
int findKRotation(vector<int> &arr)
{
    // Write your code here.

    // same logic as min element in array

    int ans = INT_MAX;
    int index = -1;

    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[start] <= arr[end])
        {
            if (ans > arr[start])
            {
                ans = arr[start];
                index = start;
            }

            break;
        }

        if (arr[start] <= arr[mid])
        {
            if (ans > arr[start])
            {
                ans = arr[start];
                index = start;
            }

            start = mid + 1;
        }
        else
        {
            if (ans > arr[mid])
            {
                ans = arr[mid];
                index = mid;
            }

            end = mid - 1;
        }
    }

    return index;
}