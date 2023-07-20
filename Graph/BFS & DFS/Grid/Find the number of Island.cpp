class Solution {
public:
    // Helper function for DFS traversal to mark all connected '1's as visited in an island.
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {

        // Mark the current cell as visited.
        visited[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        // Queue to store neighboring cells for further exploration during DFS.
        queue<pair<int, int>> q;
        q.push({row, col});

        while (!q.empty()) {
            int adjRow = q.front().first;
            int adjCol = q.front().second;
            q.pop();

            // Explore all eight adjacent cells (horizontally, vertically, and diagonally).
            for (int deltaRow = -1; deltaRow <= 1; deltaRow++) {
                for (int deltaCol = -1; deltaCol <= 1; deltaCol++) {
                    int newRow = adjRow + deltaRow;
                    int newCol = adjCol + deltaCol;

                    // Check if the new cell is within the bounds of the grid and is an unvisited '1'.
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && grid[newRow][newCol] == '1') {
                        // Mark the new cell as visited and add it to the queue for further exploration.
                        visited[newRow][newCol] = 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    } 

    // Main function to count the number of islands in the grid.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 2D vector to keep track of visited cells during DFS.
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;

        // Traverse the grid to find unvisited '1's and perform DFS to mark all connected '1's as visited.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    // Increment the count of islands and start DFS from the current '1'.
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }

        // Return the count of islands.
        return count;
    }
};
