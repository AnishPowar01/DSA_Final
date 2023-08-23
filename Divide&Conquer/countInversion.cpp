#include <bits/stdc++.h>
using namespace std;
int mergeIt(vector<int> &arr, int start, int mid, int end)
{
    int n = arr.size();

    vector<int> temp(n);

    int counter = 0;

    int left = start;
    int right = mid + 1;
    int k = start;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            temp[k++] = arr[right++];
            counter += mid - left + 1;
        }
    }

    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }

    while (right <= end)
    {
        temp[k++] = arr[right++];
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }

    return counter;
}
int merge(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }
    int counter = 0;

    int mid = start + (end - start) / 2;

    counter += merge(arr, start, mid);
    counter += merge(arr, mid + 1, end);
    counter += mergeIt(arr, start, mid, end);

    return counter;
}
int main()
{

    vector<int> arr = {2, 1, 3, 1, 2};
    int n = arr.size();

    // int counter = 0;

    // for (int i = 0; i < n - 1; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] > arr[j])
    //         {
    //             counter++;
    //         }
    //     }
    // }

    // cout << counter << "";

    int inversionCount = merge(arr, 0, n - 1);

    cout << inversionCount << "";

    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }
    return 0;
}