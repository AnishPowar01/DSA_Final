#include <bits/stdc++.h>
using namespace std;
int counter = 0;
void print(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp;

    int left = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= end)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    // count
    counter++;
    cout << "pass Number:- " << counter << endl;
    merge(arr, start, mid, end);
    print(arr, 6);
}

int main()
{
    int size = 6;

    int arr[size] = {64, 25, 12, 22, 11, 80};

    mergeSort(arr, 0, size - 1);

    print(arr, size);
}