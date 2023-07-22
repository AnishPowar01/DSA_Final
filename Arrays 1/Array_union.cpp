#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n = 5;
    int arr[n] = {1,2,3,4,9};
    int brr[3] = {5,2,6};

    for(int i = 0; i<n; i++)
    {
        int element = arr[i];

        for(int j = 0; j<3;j++)
        {
            if(brr[j] == element)
            {
                brr[j] = -1;
            }

        }
    }

    vector<int>ans;


    for(int i = 0; i<n; i++)
    {
       ans.push_back(arr[i]);
    }

    for(int i = 0; i<3; i++)
    {
        if(brr[i] !=-1)
        {
       ans.push_back(brr[i]);
            
        }
    }

    for(auto it : ans)
    {
        cout<<it<<" ";
    }

}

