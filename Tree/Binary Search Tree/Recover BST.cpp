
class Solution {
public:
    // Helper function to perform an in-order traversal and store the elements in 'ans'.
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        solve(root->left, ans); // Traverse the left subtree.
        ans.push_back(root->val); // Store the current node's value in 'ans'.
        solve(root->right, ans); // Traverse the right subtree.
    }

    // Helper function to validate the BST and recover the incorrect nodes by comparing with 'ans'.
    void validate(TreeNode* root, vector<int>& ans, int& index) {
        if (root == NULL) {
            return;
        }

        validate(root->left, ans, index); // Traverse the left subtree.

        // Compare the current node's value with the corresponding value in 'ans'.
        // If it doesn't match, correct the current node's value to 'ans[index]'.
        if (root->val != ans[index]) {
            root->val = ans[index];
        }

        index++; // Move to the next element in 'ans'.

        validate(root->right, ans, index); // Traverse the right subtree.
    }

    void recoverTree(TreeNode* root) {
        vector<int> ans; // To store the in-order traversal of the BST.

        // Perform in-order traversal and store the elements in 'ans'.
        solve(root, ans);

        // Sort the 'ans' vector to have the correct order of elements for comparison.
        sort(ans.begin(), ans.end());

        int index = 0; // To keep track of the current index in 'ans' while validating the BST.

        // Validate the BST and recover the incorrect nodes by comparing with 'ans'.
        validate(root, ans, index);
    }
};
