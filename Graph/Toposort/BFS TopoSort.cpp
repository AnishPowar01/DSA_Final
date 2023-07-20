class Solution
{
public:
    // Function to return a list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // Create an array to store the indegree of each vertex.
        int indegree[V] = {0};

        // Calculate the indegree of each vertex by traversing through the adjacency list.
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        // Create a queue to perform topological sorting using BFS.
        queue<int> q;
        vector<int> ans;

        // Add all vertices with an indegree of 0 to the queue.
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Perform BFS to find the topological order of the vertices.
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Push the current node into the answer vector as it is the next in the topological order.
            ans.push_back(node);

            // Reduce the indegree of adjacent nodes and add them to the queue if their indegree becomes 0.
            for (auto it : adj[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // Return the topological order of the vertices.
        return ans;
    }
};
