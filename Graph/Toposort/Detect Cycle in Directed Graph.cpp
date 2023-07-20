//  We know that toposort is only valid for directed acyclic graph.
// if there is cycle in graph we will not get the toposort.. so thats the idea


class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // Create an array to store the indegree of each vertex.
        int indegree[V] = {0};

        // Calculate the indegree of each vertex by traversing through the adjacency list.
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Create a queue to perform topological sorting using BFS.
        queue<int> q;
        int count = 0;

        // Add all vertices with an indegree of 0 to the queue.
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS to find the topological order of the vertices.
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            // Increment the count of visited vertices.
            count++;

            // Reduce the indegree of adjacent nodes and add them to the queue if their indegree becomes 0.
            for (auto it : adj[node]) {
                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the count of visited vertices is equal to the total number of vertices (V),
        // it means there is no cycle in the graph. Return false.
        if (count == V) {
            return false;
        }

        // If there is a cycle in the graph, the count of visited vertices will be less than V.
        // Return true in this case.
        return true;
    }
};
