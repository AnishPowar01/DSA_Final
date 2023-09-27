class Solution {
public:
    bool isValid(int row, int col, char ch, const vector<vector<char>>&board)
    {
        for(int i = 0; i<9; i++)
        {
            // row check

            if(board[row][i] == ch)
            {
                return false;
            }


            // col check

            if(board[i][col] == ch)
            {
                return false;
            }

                    // number of row + iterator  
                    // check for 3 by  3 board
            if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == ch)
            {
                return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>&board)
    {
        for(int i = 0; i<9;i++)
        {
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(char ch = '1'; ch <= '9'; ch++)
                    {
                        if(isValid(i,j,ch, board))
                        {
                            board[i][j] = ch;

                            if(solve(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
        
    }
};