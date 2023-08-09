class Solution {
    vector<string> ans; // A vector to store the binary tree paths in string format.

    // Helper function to find all binary tree paths starting from the current node.
    void solve(TreeNode* root, string temp, vector<string>& ans) {
        if (root == NULL) {
            return; // Base case: If the node is NULL, return from the function.
        }

        // If the current node is a leaf node (no left and right child), add the path to 'ans'.
        if (root->left == NULL && root->right == NULL) {
            temp = temp + to_string(root->val); // Append the current node's value to the path.
            ans.push_back(temp); // Add the path to the vector 'ans'.
            return;
        }

        string OldTemp = temp; // Store the current path before going to the left and right subtrees.

        temp = temp + to_string(root->val); // Append the current node's value to the path.
        temp.push_back('-'); // Add a '-' to separate node values in the path.
        temp.push_back('>'); // Add a '>' to indicate the direction in the path.

        // Recursively find the paths starting from the left and right subtrees.
        solve(root->left, temp, ans);
        solve(root->right, temp, ans);

        temp = OldTemp; // Backtrack: Restore the original path before exploring other subtrees.
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        string temp = ""; // Initialize an empty string to store the path temporarily.
        solve(root, temp, ans); // Call the 'solve' function to find all binary tree paths.

        return ans; // Return the vector containing all binary tree paths.
    }
};
