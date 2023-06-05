class Solution {
public:
    int n;
    int m;
    int result;
    int no_of_freeSpace;

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(int i,  int j, int count, vector<vector<int>>& grid)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] == -1)
        {
            return;
        }
        if(grid[i][j] == 2)
        {

            if(count == no_of_freeSpace)
            {
                result++;
            }
            return;
        }

        grid[i][j] = -1;

        for(auto it : directions)
        {
            int nrow = i + it[0];
            int ncol = j+ it[1];

            solve(nrow, ncol, count+1,grid);
        }

        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        int x_cord = 0;
        int y_cord = 0;

        result = 0;

        no_of_freeSpace = 0;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 0)
                {
                    no_of_freeSpace++;
                }
                if(grid[i][j] == 1)
                {

                    x_cord = i;
                    y_cord = j;

                }
            }
        }

        no_of_freeSpace += 1;     // starting point is also free space 

        int count = 0;   // as we have to visited all the empty cell .. so to keep track we will use count;


        solve(x_cord, y_cord, count, grid);


        return result;
    }
};