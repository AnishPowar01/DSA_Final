/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Create a vector to store the level order traversal
        vector<vector<int>> ans;

        // Check if the tree is empty
        if(root == NULL)
        {
            return ans;
        }

        // Create a queue to perform level order traversal
        queue<TreeNode*> q;

        // Push the root node into the queue
        q.push(root);

        // Perform level order traversal
        while(!q.empty())
        {
            // Create a vector to store the values at the current level
            vector<int> level;

            // Get the number of nodes at the current level
            int size = q.size();

            // Traverse all nodes at the current level
            while(size--)
            {
                // Get the front node from the queue
                auto it = q.front();
                q.pop();

                // Add the value of the current node to the level vector
                level.push_back(it->val);

                // Push the left child of the current node into the queue
                if(it ->left!=NULL)
                { 
                    q.push(it->left);
                }

                // Push the right child of the current node into the queue
                if(it->right!=NULL)
                {
                    q.push(it->right);
                }
            }

            // Add the level vector to the main result vector
            ans.push_back(level);
        }

        // Return the level order traversal
        return ans;
        
    }
};