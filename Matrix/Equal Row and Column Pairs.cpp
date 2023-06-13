// Approach 1 : O(n^2)

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {

        map<vector<int>, int> mp;

        // push all the rows into the map
        for (int i = 0; i < grid.size(); i++)
        {
            mp[grid[i]]++;
        }

        int ans = 0;

        //   traverse columnwise
        for (int j = 0; j < grid[0].size(); j++)
        {
            vector<int> vec;

            for (int i = 0; i < grid.size(); i++)
            {

                vec.push_back(grid[i][j]);
            }

            ans += mp[vec];
        }

        return ans;
    }
};