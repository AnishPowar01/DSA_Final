class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int dx[4] = {-1, 1, 0, 0}; // Array to represent changes in row coordinate for 4 directions: Up, Down, Left, Right
        int dy[4] = {0, 0, -1, 1}; // Array to represent changes in column coordinate for 4 directions: Up, Down, Left, Right
        
        int n = maze.size();
        int m = maze[0].size();
        
        int s_row = entrance[0]; // Row coordinate of the entrance
        int s_col = entrance[1]; // Column coordinate of the entrance
        
        queue<pair<int, int>> q; // Queue to perform BFS
        vector<vector<int>> dis(n, vector<int>(m, -1)); // 2D vector to store the distance from the entrance to each cell
        
        q.push({s_row, s_col}); // Push the entrance cell into the queue
        
        dis[s_row][s_col] = 0; // Distance from the entrance to the entrance cell is 0
        
        while (!q.empty()) {
            auto it = q.front(); // Get the front element from the queue
            q.pop(); // Pop the front element
            
            int row = it.first; // Get the row coordinate of the current cell
            int col = it.second; // Get the column coordinate of the current cell
            
            // Check if the current cell is not the entrance cell
            // If it is a boundary cell, return the distance to the nearest exit
            if (dis[row][col] != 0 && (row == 0 || row == n - 1 || col == 0 || col == m - 1)) {
                return dis[row][col];
            }
            
            // Explore the four possible adjacent cells in all four directions
            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i]; // Get the new row coordinate for the adjacent cell
                int ncol = col + dy[i]; // Get the new column coordinate for the adjacent cell
                
                // Check if the adjacent cell is within the maze boundaries, is a valid cell ('.'), and not visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && maze[nrow][ncol] == '.' && dis[nrow][ncol] == -1) {
                    q.push({nrow, ncol}); // Push the adjacent cell into the queue
                    
                    dis[nrow][ncol] = dis[row][col] + 1; // Update the distance of the adjacent cell from the entrance
                }
            }
        }
        
        // If no exit is found, return -1
        return -1;
    }
};
