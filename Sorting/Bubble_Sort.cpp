#include<bits/stdc++.h>
using namespace std;

void Bubble(int arr[], int size)
{
  

    for(int i = 0; i<size - 1; i++)
    {
    
       for(int j = 0;j<size - 1; j++)
       {
        if(arr[j] > arr[j+1])
        {
            cout<<"Swapped"<<endl;
            swap(arr[j], arr[j+1]);
    
        }

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

    int arr[size] = {10,41,7,6,14,9};

    Bubble(arr, size);

    print(arr,size);
}