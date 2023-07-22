#include<bits/stdc++.h>
using namespace std;

void solve(int index, int arr[], vector<vector<int>>&ans, vector<int>&output, int m , int n)
{
    if(index == n )
    {
        if(output.size() == m)
        {
         ans.push_back(output);
        }
        
        return;
    }

    
    solve(index+1, arr, ans, output, m, n);

    output.push_back(arr[index]);
    solve(index+1, arr, ans, output, m, n);
    output.pop_back();
}

int findNumber(int arr[], int n, int m)
{
    vector<vector<int>>ans;
    vector<int>output;

    solve(0,arr, ans, output, m, n);

    // for(auto it : ans)
    // {
    //     for(auto i : it)
    //     {
    //         cout<<i<<" ";
    //     }

    //     cout<<endl;
    // }

    int diff = INT_MAX;

     for(auto it : ans)
     {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(auto i : it)
        {
            if(i > maxi)
            {
                maxi = i;
            }

            if(i < mini)
            {
                mini = i;
            }
        }

        diff = min(diff, maxi - mini);
     }

     return diff;
}

int findMin(int arr[], int n, int m)
{
    sort(arr, arr+n);

    int diff = INT_MAX;

    for(int i = 0; i+m-1 <n; i++)
    {
        int newDiff = arr[i+m-1] - arr[i];

        diff = min(diff, newDiff);
    }

    return diff;
}
int main()
{
    int n = 7;

    int arr[n] = {7, 3, 2, 4, 9, 12, 56};

    int m = 3;


    // int ans = findNumber(arr , n, m);
    int ans = findMin(arr , n, m);

    cout<<ans<<""; 
}