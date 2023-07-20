class Solution {
  private:
      void DFS(int start, int visited[], vector<int>&ans, vector<int>adj[])
      {
          if(visited[start] == 1)
          {
              return ;
          }
          
           visited[start] = 1;
           
           ans.push_back(start);
          
          for(auto  it : adj[start])
          {
              if(visited[it]!=1)
              {
                  DFS(it,visited,ans, adj);
              }
          }
      }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        int visited[V] = {0};
        
        vector<int>ans;
        
        DFS(0, visited,ans,adj);
        
        
        return ans;
    }
};