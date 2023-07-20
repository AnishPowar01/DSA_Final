class Solution {
public:
    // Function to find the eventual safe nodes in the graph.
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // Create a new graph (adjacency list) to represent the reverse edges.
        vector<int> adj[n];

        // Create an array to store the indegree of each node.
        vector<int> indegree(n, 0);

        // Build the reverse graph and calculate the indegree of each node.
        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i); // Reverse edge from it to i in the reverse graph.
                indegree[i]++; // Increment the indegree of node i.
            }
        }

        vector<int> ans; // Create a vector to store the eventual safe nodes.
        queue<int> q; // Create a queue to perform topological sorting.

        // Add all nodes with an indegree of 0 to the queue (i.e., the nodes with no outgoing edges).
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS-based topological sorting on the reverse graph.
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node); // Add the current node to the eventual safe nodes.

            // Reduce the indegree of adjacent nodes and add them to the queue if their indegree becomes 0.
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Sort the eventual safe nodes in ascending order.
        sort(ans.begin(), ans.end());

        return ans; // Return the vector of eventual safe nodes.
    }
};
