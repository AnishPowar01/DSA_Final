#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {10, 3, 40, 20, 50, 80, 65};
    int target = 10;

    // in nearly sorted array the actual position of i th element can be found at i-1, i or i+1 th index.

    int start = 0;
    int end = nums.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
        {
            cout << mid << " ";
            break;
        }
        if (mid - 1 >= 0 && nums[mid - 1] == target)
        {
            cout << mid - 1 << " ";
            break;
        }
        if (mid + 1 < nums.size() && nums[mid + 1] == target)
        {
            cout << mid + 1 << " ";
            break;
        }

        else if (target > nums[mid])
        {
            start = mid + 2;
        }
        else
        {
            end = mid - 2;
        }
    }
    return 0;
}