class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid) {
        
        // Step 1: Initialize a queue to perform BFS and a 2D vector to keep track of visited cells.
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        // Step 2: Push all 'O' cells on the border into the queue and mark them as visited.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n-1 || j == 0 || j == m-1) {
                    if (grid[i][j] == 'O') {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }
        
        // Arrays to represent the changes in row and column indices to move in all four directions.
        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        
        // Step 3: Perform BFS to mark all connected 'O' cells as visited starting from the border cells.
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int row = it.first;
            int col = it.second;
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];
                
                // Check if the new cell is within the bounds of the grid and not visited yet, and is also an 'O'.
                if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && !visited[nrow][ncol] && grid[nrow][ncol] == 'O') {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        
        // Step 4: Traverse the grid again and change all unvisited 'O' cells to 'X'.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == 'O') {
                    grid[i][j] = 'X';
                }
            }
        }
        
        // Step 5: Return the updated grid.
        return grid;
    }
};
