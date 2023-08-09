
class Solution {
public:
    // Function to find the value of the leftmost node in the last level of the binary tree.
    int findBottomLeftValue(TreeNode* root) {
        int currentLeftValue = 0; // Variable to store the value of the leftmost node.

        if (root == NULL) {
            return 0; // Base case: If the root is NULL, return 0 (empty tree).
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (i == 0) {
                    // If it is the first node at the current level, update the 'currentLeftValue'.
                    currentLeftValue = temp->val;
                }

                if (temp->left != NULL) {
                    q.push(temp->left); // Add the left child to the queue.
                }

                if (temp->right != NULL) {
                    q.push(temp->right); // Add the right child to the queue.
                }
            }
        }

        // Return the value of the leftmost node in the last level of the binary tree.
        return currentLeftValue;
    }
};
