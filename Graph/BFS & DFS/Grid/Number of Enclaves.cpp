class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // Get the number of rows and columns in the grid
        int n = grid.size();
        int m = grid[0].size();

        // Arrays to represent the changes in row and column indices to move in all four directions.
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};

        // 2D vector to keep track of visited cells during BFS
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Queue for BFS traversal
        queue<pair<int, int>> q;

        // Check for land cells in the first row, last row, first column, and last column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    // If it is a land cell (1), store it in the queue and mark it as visited
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }

        // Perform BFS traversal starting from the border land cells
        while (!q.empty()) {
            int initialRow = q.front().first;
            int initialCol = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = initialRow + deltaRow[i];
                int ncol = initialCol + deltaCol[i];

                // Check if the new cell is within the bounds of the grid, unvisited, and is a land cell (1)
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1) {
                    visited[nrow][ncol] = true;
                    q.push({nrow, ncol});
                }
            }
        }

        // Count the number of unvisited land cells (1s) that are not connected to the border
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};
