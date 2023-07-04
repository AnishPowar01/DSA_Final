#include<bits/stdc++.h>
using namespace std;
int findPartition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start;
    int j = end;

    while (i < j)
    {
        while (arr[i] <= pivot && i < end)
        {
            i++;
        }

        while (arr[j] > pivot && j >= start)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[start], arr[j]);

    return j;
}
void QuickSort(int arr[], int start, int end)
{

    if(start < end)
    {


    int partition = findPartition(arr, start, end);

    
    QuickSort(arr, start, partition -1 );
  
    QuickSort(arr, partition+1, end);
   
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

    QuickSort(arr, 0,size-1);

    print(arr, size);

}
