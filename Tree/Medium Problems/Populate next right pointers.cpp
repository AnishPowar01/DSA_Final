class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL; // Base case: If the tree is empty, return NULL.
        }

        queue<Node*> q;
        q.push(root); // Push the root node into the queue.

        while (!q.empty()) {
            int size = q.size();

            // Process nodes at the current level (Breadth-First Traversal).
            while (size--) {
                Node* temp = q.front();
                q.pop();

                // If there is still a node in the current level, set 'temp->next' to point to it.
                if (q.size() >= 1 && size >= 1) {
                    temp->next = q.front();
                }

                // Push the left and right children of the current node into the queue.
                if (temp->left != NULL) {
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    q.push(temp->right);
                }
            }
        }

        return root; // Return the updated root of the tree.
    }
};
