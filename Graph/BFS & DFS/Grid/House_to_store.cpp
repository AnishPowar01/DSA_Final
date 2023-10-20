#include <bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<vector<char>> &matrix, vector<vector<bool>> &visited)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (row >= n || col >= m || row < 0 || col < 0 || matrix[row][col] != 'H' || visited[row][col] == true)
    {
        return false;
    }

    return true;
}
vector<vector<int>> findDistance(vector<vector<char>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> distance(n, vector<int>(m, 1e9));

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    queue<pair<int, pair<int, int>>> q;
    //         steps, row, col

    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 'S')
            {
                q.push({0, {i, j}});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int steps = it.first;
        int row = it.second.first;
        int col = it.second.second;

        distance[row][col] = steps;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (isValid(nrow, ncol, matrix, visited))
            {
                q.push({steps + 1, {nrow, ncol}});
                visited[nrow][ncol] = true;
            }
        }
    }

    return distance;
}
int main()
{
    vector<vector<char>> matrix = {{'H', 'H', 'H', 'S', 'H'},
                                   {'S', 'H', 'H', 'S', 'H'},
                                   {'H', 'S', 'H', 'H', 'S'}};

    vector<vector<int>> ans = findDistance(matrix);

    for (auto it : ans)
    {
        for (auto a : it)
        {
            cout << a << " ";
        }

        cout << endl;
    }
    return 0;
}