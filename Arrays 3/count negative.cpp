
// Approach 1 : O(n*m)  Brute 

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int start = 0;
        int end = m*n;
    }
};


// Approach 2 : o(nlog(m));  Better

class Solution {

    private:

    int binarySearch(vector<int>ans)
    {
        int start = 0;
        int end = ans.size()-1;


        while(start <= end)
        {
            int mid  = start + (end - start)/ 2;

            if(ans[mid] < 0)
            {
                
                end = mid -1;

            }
            else

            {
                start = mid +1;
            }
            
        }

        return (ans.size() - end - 1);
    }

    public:
     int countNegatives(vector<vector<int>>& grid) {

         int counter = 0;

         for(int i = 0; i<grid.size(); i++)
         {
             counter += binarySearch(grid[i]);
         }

         return counter;


     }
};




// Approach 3 : O(n + m);   Best;

class Solution {
    public:
    int countNegatives(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int i = n-1;
        int j = 0;

        int ans = 0;

        while(i>=0 && j<m)
        {
            if(grid[i][j] < 0)
            {
                i--;

                ans += m -j;
            }
            else
            {
                j++;
            }
        }

        return ans;

    }
};