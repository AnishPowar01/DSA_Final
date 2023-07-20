class Solution {
private:
    void BFS(int start, unordered_map<int, vector<int>> &adj, vector<bool>&visited)
    {
        queue<int>q;

        q.push(start);

        visited[start] = 1;

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();


            for(auto it : adj[node])
            {
                if(!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;

        int n = isConnected.size();

        vector<bool> visited(n,false);


        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {

                if(isConnected[i][j] == 1 && i!=j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }



        int count = 0;

        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                count++;
                BFS(i,adj,visited);
            }
        }

        return count;
    }
};