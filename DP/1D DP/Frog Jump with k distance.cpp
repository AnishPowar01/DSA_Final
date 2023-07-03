//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int solve(vector<int>&nums, int index, int k, vector<int>&dp)
      {
          if(index == 0)
          {
              return 0;
          }
          
          if(dp[index]!=-1)
          {
              return dp[index];
          }
          
          int ans = INT_MAX;
          
          for(int i = 1; i<=k; i++)
          {
             if(index - i >= 0)
             {
                 int jump = abs(nums[index] - nums[index - i]) + solve(nums, index -  i, k,dp);
                 ans = min(jump, ans);
             }
          }
          
          return dp[index] =  ans;
          
          
      }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        
        vector<int>dp(n+1, -1);
        
        return solve( height, n-1, k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends