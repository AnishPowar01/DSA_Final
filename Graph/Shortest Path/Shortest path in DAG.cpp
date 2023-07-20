#include<bits/stdc++.h>
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here

    unordered_map<int,vector<pair<int,int>>>adj;

    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v,wt});
    }

    vector<int>distance(n, 1e9);

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>q;

    q.push({0,0});

    distance[0] = 0;

    while(!q.empty())
    {
        auto it = q.top();
        q.pop();

        int wt= it.first;
        int node = it.second;


        for(auto it : adj[node])
        {
            int adj = it.first;
            int wei = it.second;

            if(wt + wei < distance[adj])
            {
                distance[adj] = wt + wei;

                q.push({distance[adj], adj});
            }
            
        }

    }

    for(int i = 0; i<distance.size(); i++)
    {
        if(distance[i] == 1e9)
        {
            distance[i] = -1;
        }
    }

    return distance;
}

