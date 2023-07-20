
// Push the coordinates of all 0s into the queue and mark them as visited in the visited matrix. Set the distances for these 0s as 0, as they are already at distance 0 from themselves.

//  pop the front element from the queue, which contains the row, column, and steps taken to reach that cell from a 0.

// Update the distance of the current cell in the distance matrix with the steps taken to reach it from the nearest 0.

// Check all four adjacent cells (up, right, down, left) from the current cell. If a neighboring cell is within the bounds of the matrix and has not been visited yet (i.e., its value in the visited matrix is 0), add it to the queue, mark it as visited, and increment the distance by 1.

// Repeat the process until the queue becomes empty, which means all cells have been visited and their distances from the nearest 0 have been calculated.

// Return the distance matrix, which contains the minimum distances of each 1 in the input matrix from the nearest 0.

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

			int n = mat.size();
			int m = mat[0].size();

			vector<vector<int>>visited(n,vector<int>(m,0));

			vector<vector<int>>distance(n,vector<int>(m,0));

			queue<pair<pair<int,int>,int>>q;

			 for(int i= 0; i<n; i++)
			 {
				 for(int j = 0; j<m; j++)
				 {
					 if(mat[i][j] == 0)
					 {
						 q.push({{i,j},0});
						 visited[i][j] = 1;
					 }
					 else
					 {
						 visited[i][j] = 0;
					 }
				 }
			 }


			int deltaRow[] = {-1,0,1,0};
        int deltaCol[] = {0,1,0,-1};

				while(!q.empty())
				{
					int row = q.front().first.first;

					int col = q.front().first.second;

					int steps = q.front().second;

					q.pop();

					distance[row][col] = steps;

					for(int i = 0; i<4; i++)
					{
						int newRow = row + deltaRow[i];
						int newCol = col + deltaCol[i];


						if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && visited[newRow][newCol] == 0)
						{
							q.push({{newRow,newCol},steps+1});
							visited[newRow][newCol] = 1;
						}
					}
				}


				return distance;
        
    }
};