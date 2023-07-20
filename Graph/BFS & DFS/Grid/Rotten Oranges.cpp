class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        int n = grid.size();
        int m = grid[0].size();

        int visited[n][m];

        // bfs
        // {{row,col}, time};

        int count = 0;

        queue<pair<int,pair<int,int>>>q;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({0,{i,j}});

                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }


                if(grid[i][j] == 1)
                {
                    count++;
                }
            }
        }


        int maxTime = 0;
        int freshCount = 0;


        while(!q.empty())
        {
            int row = q.front().second.first;
            int col = q.front().second.second;

            int time = q.front().first;

            q.pop();

            maxTime = max(maxTime, time);

            for(int i = 0; i<4; i++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];

                if(nrow >= 0 && nrow < n && ncol < m && ncol>= 0 && visited[nrow][ncol]!=2 && grid[nrow][ncol] == 1)
                {
                    q.push({time+1, {nrow, ncol}});
                    visited[nrow][ncol] = 2;

                    freshCount++;
                }
            }
        }

        if(count!= freshCount) return -1;


        return maxTime;

        
        
    }
};