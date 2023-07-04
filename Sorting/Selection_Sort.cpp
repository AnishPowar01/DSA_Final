#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size)
{

    for(int i = 0; i<size - 1; i++)
    {
        int minIndex = i;

        for(int j = i+1; j<size; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[minIndex], arr[i]);
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

    selectionSort(arr, size);

    print(arr,size);
}