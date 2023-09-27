class Solution {
public:
bool isSafe(int row, int col, vector<string>&ans,int n)
    {
        int x = row; 
        int y = col;
         
        //  staright line
         while(y>=0)
         {
            if(ans[x][y] == 'Q')
                return false;

            y--;    
         }

        //  left diagonal

        x = row;
        y = col;

        while(x>=0 && y>=0)
        {
            if(ans[x][y] == 'Q')
            {
                return false;
            }

            x--;
            y--;
        }


        // right digonal

        x = row; 
        y = col;

        while(x<n && y>=0)
        {
            if(ans[x][y] == 'Q')
            {
                return false;
            }

            x++;
            y--;
        }

        return true;

    }
    int solve(vector<string>&ans, int n ,int col)
    {
        if(col == n)
        {
            return 1;
        }

        int count = 0;


        for(int row = 0; row<n; row++)
        {
            if(isSafe(row,col,ans, n))
            {
                ans[row][col] = 'Q';

               count+=solve(ans,n, col+1);

                ans[row][col] = '.';
            }
        }

        return count;
    }
    int totalNQueens(int n) {

        vector<string>board(n);

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                board[i].push_back('.');
            }
        }


        return solve(board,n,0);
        
    }
};