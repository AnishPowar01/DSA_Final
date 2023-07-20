class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>ans;
        
        queue<int>q;
        
        int visited[V] = {0};
        
         q.push(0);
        
        visited[0] = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            
            ans.push_back(node);
            
            for(auto it : adj[node])
            {
                
                if(!visited[it])
                {
                    q.push(it);
                    visited[it] = 1;
                }
                
            }
        }
        
        return ans;
    }
};