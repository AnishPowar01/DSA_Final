#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to perform Depth-First Search (DFS) and detect cycles in the graph.
// It returns true if a cycle is found, otherwise false.
bool dfs(int start, int parent, unordered_map<int, vector<int>>& adj, vector<int>& visited, int n) {
    visited[start] = 1; // Mark the current node as visited.

    // Traverse through all adjacent nodes of the current node.
    for (auto it : adj[start]) {
        if (!visited[it]) {
            // If the adjacent node is not visited yet, perform DFS from that node.
            // If DFS from the adjacent node returns true (indicating a cycle), return true.
            if (dfs(it, start, adj, visited, n)) {
                return true;
            }
        } else if (it != parent) {
            // If the adjacent node is already visited and it is not the parent of the current node,
            // it means there is a back edge, and the graph contains a cycle. Return true.
            return true;
        }
    }

    return false; // If no cycle is found from the current node, return false.
}

int main() {
    unordered_map<int, vector<int>> adj;
    int edges, n;

    cin >> n; // Input the number of nodes in the graph.
    cin >> edges; // Input the number of edges in the graph.

    // Input the edges and create the adjacency list.
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u;
        cin >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n, 0); // Create a vector to keep track of visited nodes during DFS.
    bool hasCycle = false; // Initialize a boolean variable to track if the graph contains a cycle.

    // Traverse through all nodes in the graph and perform DFS starting from unvisited nodes.
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // If DFS from any node returns true (indicating a cycle), set hasCycle to true and break the loop.
            if (dfs(i, -1, adj, visited, n)) {
                hasCycle = true;
                break;
            }
        }
    }

    // Output the result based on whether the graph contains a cycle or not.
    if (hasCycle) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}
