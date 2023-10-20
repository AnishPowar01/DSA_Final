#include <bits/stdc++.h>
using namespace std;
int solve(int index, vector<int> &nums, int target)
{
    if (index == 0)
    {
        if (target % nums[0] == 0)
        {
            return target / nums[0];
        }
        else
        {
            return 1e8;
        }
    }

    int notTake = solve(index - 1, nums, target);

    int Take = 1e8;

    if (nums[index] <= target)
    {
        Take = 1 + solve(index, nums, target - nums[index]);
    }

    return min(notTake, Take);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 6};

    int n = arr.size();

    int ans = solve(n - 1, arr, 10);

    cout << ans << "";
    return 0;
}
