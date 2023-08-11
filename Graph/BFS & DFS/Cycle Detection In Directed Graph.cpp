#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int start, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited)
    {
        if (pathVisited[start])
        {
            return true; // Detected a cycle
        }

        if (visited[start])
        {
            return false; // Already visited this node, no cycle found here
        }

        visited[start] = true;
        pathVisited[start] = true;

        for (auto &it : adj[start])
        {
            if (dfs(it, adj, visited, pathVisited))
            {
                return true;
            }
        }

        pathVisited[start] = false;

        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, pathVisited))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
