#include <bits/stdc++.h>
using namespace std;
// Number of comparisons :- 3n/2 - 2
// Time complexity = O(n);
// without using d&c => 2 * (n-1) => comparison
void solve(vector<int> arr, int i, int j, int &mini, int &maxi)
{
    if (i == j)
    {
        maxi = arr[i];
        mini = arr[i];
        return;
    }

    if (i == j - 1)
    {
        if (arr[i] > arr[j])
        {
            maxi = arr[i];
            mini = arr[j];
        }
        else
        {
            maxi = arr[j];
            mini = arr[i];
        }
        return;
    }

    int mid = (i + j) / 2;

    solve(arr, i, mid, mini, maxi);

    int mini1 = mini;
    int maxi1 = maxi;

    solve(arr, mid + 1, j, mini1, maxi1);

    if (mini > mini1)
    {
        mini = mini1;
    }

    if (maxi < maxi1)
    {
        maxi = maxi1;
    }
}
int main()
{
    vector<int> arr = {8, 10, 0, -5, -8 ,18, 2, 9, 2, 30, 25};

    int mini = INT_MAX;
    int maxi = INT_MIN;

    solve(arr, 0, arr.size() - 1, mini, maxi);

    cout << mini << "" << endl;
    cout << maxi << "" << endl;
    return 0;
}