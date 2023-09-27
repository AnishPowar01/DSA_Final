

#include <bits/stdc++.h>
using namespace std;


class Solution{
    private:
    void solve(int i, int j , vector<vector<int>>&arr, string temp, vector<string>&ans,vector<vector<int>>&visited, int n)
    {
        if(i<0 || j <0 || i >=n || j >=n ||arr[i][j] == 0 || visited[i][j] == 1)
        {
            return ;
        }
        
        if(i==arr.size()-1 && j == arr[0].size()-1)
        {
            ans.push_back(temp);
            return ;
        }
        
        
        visited[i][j] = 1;
        
        solve(i+1,j,arr, temp + 'D', ans,visited,n);
        solve(i-1,j,arr, temp + 'U', ans,visited,n);
        solve(i,j+1,arr, temp + 'R', ans,visited,n);
        solve(i,j-1,arr, temp + 'L', ans,visited,n);
        
        visited[i][j] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        string temp = "";
        vector<string>ans;
        
        vector<vector<int>>visited(n, vector<int>(n,0));
        
        solve(0,0,m, temp, ans, visited,n);
        
        return ans;
    }
};

    

