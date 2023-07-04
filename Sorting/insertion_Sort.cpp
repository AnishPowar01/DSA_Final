#include<bits/stdc++.h>
using namespace std;

void insertion(int arr[], int size)
{

    for(int i = 0; i<size-1; i++)
    {
        int j = i;

        while(j>0 && arr[j-1] > arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
    }

}

void print(int arr[], int size)
{

    for(int i = 0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int size = 6;

    int arr[size] = {64,25,12,22,11,80};

    insertion(arr, size);

    print(arr,size);
}