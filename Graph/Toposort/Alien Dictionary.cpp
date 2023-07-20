// User function Template for C++

// dry run
// dict = {"baa","abcd","abca","cab","cad"}
// baa
// abcd
// abca
// cab
// cad

// compare(baa,abcd)
// as b is appear before the a in aliens dictionary..
// so we can form edge between them
// b -> a

// compare abcd and abca
// here last charachter is not matching so.,
// d appears before a
// d -> a

// simialry do this for all..  and apply toposort.

class Solution{
public:
    // Function to perform topological sorting using BFS.
    vector<int> topoSort(vector<int> adj[], int V) {
        int indegree[V] = {0};
        vector<int> topo;

        // Calculate the indegree of each vertex by traversing the adjacency list.
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        // Add all vertices with an indegree of 0 to the queue.
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS to find the topological order of the vertices.
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node); // Add the current node to the topological order.

            // Reduce the indegree of adjacent nodes and add them to the queue if their indegree becomes 0.
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo; // Return the topological order of the vertices.
    }

    string findOrder(string dict[], int N, int K) {
        // Code here

        // Create an adjacency list to represent the directed edges between characters.
        vector<int> adj[K];

        // Build the adjacency list by comparing adjacent words and finding character relationships.
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.length(), s2.length());

            for (int index = 0; index < len; index++) {
                if (s1[index] != s2[index]) {
                    adj[s1[index] - 'a'].push_back(s2[index] - 'a');
                    break;
                }
            }
        }

        // Perform topological sorting to find the correct order of characters.
        vector<int> ans = topoSort(adj, K);

        string result = "";

        // Convert the characters back to a string and return the result.
        for (auto it : ans) {
            result = result + char(it + 'a');
        }

        return result;
    }
};
