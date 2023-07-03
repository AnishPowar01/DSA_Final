//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Recursive + Memoization

class Solution {
  public:
      int solve(int day, vector<vector<int>>&nums, int last, vector<vector<int>>&dp)
      {
          if(day == 0)
          {
              int maxi = 0;
              
              for(int i = 0; i<3; i++)
              {
                  if(i!=last)
                  {
                      maxi = max(maxi, nums[0][i]); 
                  }
              }
              return maxi;
          }
          
          if(dp[day][last]!=-1)
          {
              return dp[day][last];
          }
          
          int maxi = 0;
          
          
          for(int i = 0; i<3; i++)
          {
              if(i!=last)
              {
                  int point = nums[day][i] + solve(day-1, nums, i,dp);
                  maxi = max(maxi, point);
              }
          }
          
          return dp[day][last] =  maxi;
      }


    //   Tabulation
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4, 0));
        
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max({points[0][0], points[0][1], points[0][2]});
        
        for(int days = 1; days<n; days++)
        {
            for(int last = 0; last<4; last++)
            {
                dp[days][last] = 0;
             

                for(int task = 0; task<3; task++)
                {
                    if(task!=last)
                    {
                    int point = points[days][task] + dp[days-1][task];
                    dp[days][last]  = max( dp[days][last],point);
                        
                    }

                }
            }
        }
        
        return dp[n-1][3]; 
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends