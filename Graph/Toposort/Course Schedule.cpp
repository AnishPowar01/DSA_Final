// write toposort directly...


class Solution {
public:
    // Function to check if it is possible to finish all courses.
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Create a graph using an unordered_map to store the adjacency list.
        unordered_map<int, vector<int>> adj;

        // Build the graph by adding prerequisites as directed edges.
        for (auto it : prerequisites) {
            int u = it[0]; // Course u is a prerequisite for course v.
            int v = it[1];
            adj[u].push_back(v);
        }

        // Create vectors to keep track of visited nodes and the indegree of each node.
        vector<int> visited(numCourses, false);
        vector<int> indegree(numCourses, 0);

        // Calculate the indegree of each course.
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Create a queue to perform topological sorting.
        queue<int> q;

        // Add all courses with an indegree of 0 to the queue.
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int counter = 0; // Initialize a counter to keep track of the number of courses completed.

        // Perform BFS-based topological sorting.
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            counter++; // Increment the counter for each course completed.

            // Reduce the indegree of adjacent nodes and add them to the queue if their indegree becomes 0.
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the counter is not equal to the total number of courses, it means there is a cycle
        // or some courses cannot be completed. Return false in this case.
        if (counter != numCourses) {
            return false;
        }

        return true; // If all courses can be completed, return true.
    }
};
