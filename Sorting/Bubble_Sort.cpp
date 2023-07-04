#include<bits/stdc++.h>
using namespace std;

void Bubble(int arr[], int size)
{
  

    for(int i = 0; i<size - 1; i++)
    {
        bool isSorted = false;
       for(int j = i+1;j<size; j++)
       {
        if(arr[i] > arr[j])
        {
            cout<<"Swapped"<<endl;
            swap(arr[i], arr[j]);
            isSorted = true;
        }

       }
        // optimization
       if(isSorted == false)
       {
        cout<<"Array is Already Sorted"<<endl;
        break;
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

    int arr[size] = {1,2,3,4,5,6};

    Bubble(arr, size);

    print(arr,size);
}