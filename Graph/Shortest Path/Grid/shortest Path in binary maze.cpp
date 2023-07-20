class Solution {
    vector<vector<int>>direction = {
                 
        {-1,-1},   {-1,0}       ,{-1,1},

        {0,-1},                  {0,1},

        {1,-1},    {1,0},        {1,1}
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m, 1e9));

        dist[0][0] = 0;

        queue<pair<int,pair<int,int>>> q;

        if(grid[0][0] == 1)
        {

            return -1;
        }

        q.push({1,{0,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int dista = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1)
            {
                return dista;
            }


            for(auto it : direction)
            {
                int nrow = row + it[0];
                int ncol = col + it[1];

                if(nrow < n && nrow >= 0 && ncol <m && ncol >= 0 && grid[nrow][ncol] == 0 && dista + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = dista + 1;

                    if(nrow == n-1 && ncol == m-1)
                    {
                        return dist[n-1][m-1];
                    }

                    q.push({1+dista,{nrow,ncol}});
                }


            }
        }

        return -1;

       
    }
};