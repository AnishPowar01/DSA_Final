class Solution {
private:
    bool isFound(int i, int j, vector<vector<char>>&nums, string&word, int index, int n, int m)
    {
        if(index == word.length())
        {
            return true;
        }

        if(i<0 || j <0 || i>=n || j>=m || nums[i][j] != word[index] || nums[i][j] == '&')
        {
            return false;
        }

        char ch = nums[i][j];

        nums[i][j] = '&';

        bool top = isFound(i-1, j, nums, word, index+1, n,m);
        bool bottom = isFound(i+1, j, nums, word, index+1, n,m);
        bool left = isFound(i, j-1, nums, word, index+1, n,m);
        bool right = isFound(i, j+1, nums, word, index+1, n,m);
        
        // backtracking
        nums[i][j] = ch;

        return top || bottom || left || right;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i =0; i<n; i++)
        {
            for(int j =0; j<m; j++)
            {
                if(isFound(i,j,board, word, 0, n,m) == true)
                {
                    return true;
                }
            }
        }

        return false;
        
    }
};