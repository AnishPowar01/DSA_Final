vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.

    unordered_map<int,vector<int>>adj;

    for(auto it : edges)
    {
        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int>distance(n, 1e9);
    

    queue<int>q;

    q.push(src);

    distance[src] = 0;


    while(!q.empty())
    {
        auto node = q.front();
        q.pop();

        for(auto it : adj[node])
        {
            if(distance[node] + 1 < distance[it])
            {
                distance[it] = distance[node] +1;

                q.push(it);
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