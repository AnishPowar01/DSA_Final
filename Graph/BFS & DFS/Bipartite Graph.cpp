class Solution {
private:
    // Helper function for DFS traversal to check if the graph is bipartite.
    // It colors the nodes alternatively (0 and 1) and checks if adjacent nodes have different colors.
    // Returns false if any adjacent nodes have the same color, indicating that the graph is not bipartite.
    bool dfs(int currentNode, vector<vector<int>>& graph, vector<int>& color, int currentColor) {
        // Color the current node with the currentColor (0 or 1).
        color[currentNode] = currentColor;

        // Traverse all adjacent nodes of the current node.
        for (int& it : graph[currentNode]) {
            // If the adjacent node is not colored yet, color it with the opposite color of the current node.
            if (color[it] == -1) {
                int colorOFit = !color[currentNode];
                
                // Perform DFS on the adjacent node with the new color.
                if (dfs(it, graph, color, colorOFit) == false) {
                    return false; // If DFS returns false, the graph is not bipartite.
                }
            } else if (color[it] == color[currentNode]) {
                // If the adjacent node has the same color as the current node, the graph is not bipartite.
                return false;
            }
        }

        return true; // If all adjacent nodes have different colors, the graph is bipartite.
    }

public:
    // Function to check if a graph is bipartite.
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // Create a vector to keep track of colors of nodes during DFS traversal.
        // -1 indicates that the node is not colored yet.
        // 0 and 1 represent two different colors used for bipartition.
        vector<int> color(n, -1);

        // Traverse through all nodes in the graph and perform DFS starting from uncolored nodes.
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                // If DFS starting from any node returns false, the graph is not bipartite.
                if (dfs(i, graph, color, 1) == false) {
                    return false;
                }
            }
        }

        return true; // If DFS completes for all nodes without any conflicts, the graph is bipartite.
    }
};
