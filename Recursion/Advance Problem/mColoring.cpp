
class Solution
{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
    {
        for (int k = 0; k < n; k++)
        {
            if (k != node && graph[k][node] == 1 && color[k] == col)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(int index, bool graph[101][101], int m, int n, int color[])
    {
        if (index == n)
        {
            return true;
        }

        for (int i = 1; i <= m; i++)
        {
            if (isSafe(index, color, graph, n, i))
            {
                color[index] = i;

                if (solve(index + 1, graph, m, n, color))
                {
                    return true;
                }

                color[index] = 0;
            }
        }

        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n)
    {

        int color[n] = {0};

        if (solve(0, graph, m, n, color))
        {
            return true;
        }

        return false;
    }
};
