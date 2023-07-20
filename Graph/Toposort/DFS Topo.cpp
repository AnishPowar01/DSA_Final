class Solution
{
private:
    // DFS function to perform topological sorting of the graph.
    // It visits all the vertices reachable from the 'start' vertex and pushes them onto the stack.
    void dfs(int start, stack<int>& st, vector<int>& visited, vector<int> adj[])
    {
        visited[start] = 1; // Mark the current vertex as visited.

        // Traverse through all adjacent vertices of the current vertex.
        for (auto it : adj[start])
        {
            if (!visited[it])
            {
                // If the adjacent vertex is not visited yet, perform DFS from that vertex.
                dfs(it, st, visited, adj);
            }
        }

        // After visiting all reachable vertices, push the current vertex onto the stack.
        st.push(start);
    }

public:
    // Function to return a list containing vertices in topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // Create a vector to keep track of visited vertices during DFS.
        vector<int> visited(V, 0);

        // Create a stack to store the vertices in reverse topological order.
        stack<int> st;

        // Perform DFS starting from all unvisited vertices.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, st, visited, adj);
            }
        }

        // Create a vector to store the final topological order.
        vector<int> ans;

        // Pop elements from the stack and add them to the 'ans' vector to get the topological order.
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        // Return the topological order of the vertices.
        return ans;
    }
};
