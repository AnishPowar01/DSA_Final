class Solution {
public:
    // Function to find the order of courses to take.
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an array of vectors to represent the graph.
        vector<int> adj[numCourses];

        // Build the graph by adding prerequisites as directed edges.
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // Course it[1] is a prerequisite for course it[0].
        }

        // Create a vector to store the indegree of each course.
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
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans; // Create a vector to store the order of courses to take.

        // Perform BFS-based topological sorting.
        while (!q.empty()) {
            int start = q.front();
            q.pop();

            ans.push_back(start); // Add the current course to the answer vector.

            // Reduce the indegree of adjacent nodes and add them to the queue if their indegree becomes 0.
            for (auto it : adj[start]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // If the number of courses in the answer vector is equal to the total number of courses,
        // it means all courses can be taken in the given order. Return the answer vector.
        if (ans.size() == numCourses) {
            return ans;
        }

        return {}; // If not all courses can be taken, return an empty vector.
    }
};
