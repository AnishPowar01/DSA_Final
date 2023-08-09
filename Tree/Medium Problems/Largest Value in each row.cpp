
class Solution {
public:
    // Function to find the largest value in each row of the binary tree.
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans; // Vector to store the largest value in each row.

        if (root == NULL) {
            return ans; // Base case: If the root is NULL, return an empty vector.
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int maxi = INT_MIN; // Variable to store the maximum value in the current row.

            // Traverse all nodes at the current level and find the maximum value.
            while (size--) {
                auto it = q.front();
                q.pop();

                maxi = max(maxi, it->val); // Update the maximum value if needed.

                if (it->left != NULL) {
                    q.push(it->left); // Add the left child to the queue.
                }

                if (it->right != NULL) {
                    q.push(it->right); // Add the right child to the queue.
                }
            }

            ans.push_back(maxi); // Store the maximum value of the current row in the 'ans' vector.
        }

        return ans; // Return the vector containing the largest values in each row.
    }
};
