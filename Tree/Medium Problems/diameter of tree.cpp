
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
    // Helper function to calculate the height of the binary tree and update the diameter.
    int height(TreeNode* root, int& diameter) {
        // Base case: If the root is NULL (empty tree), its height is 0.
        if (!root) {
            return 0;
        }

        // Recursively calculate the heights of the left and right subtrees.
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        // Update the diameter if the sum of left and right subtree heights is greater than the current diameter.
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current node (adding 1 for the current node itself).
        return 1 + max(leftHeight, rightHeight);
    } 

    // Function to calculate the diameter of the binary tree.
    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize the diameter to 0.
        int diameter = 0;

        // Call the helper function to calculate the height of the binary tree and update the diameter.
        height(root, diameter);

        // Return the final diameter of the binary tree.
        return diameter; 
    }
};


// Explanation:
// 1. The function `height` is a helper function that calculates the height of the binary tree rooted at the given `root` node. Additionally, it updates the `diameter` of the binary tree if a longer diameter is found during the height calculation.
// 2. The base case of the recursion is when the `root` is NULL, which indicates an empty tree. In this case, the height is 0.
// 3. For a non-empty tree, the function recursively calculates the heights of the left and right subtrees by calling `height` on the left and right child nodes, respectively.
// 4. After calculating the heights of the left and right subtrees, the function updates the `diameter` by taking the maximum of the current diameter and the sum of left and right subtree heights.
// 5. The height of the current node is then returned by adding 1 to the maximum of the heights of the left and right subtrees.
// 6. The `diameterOfBinaryTree` function is the main function that calculates the diameter of the binary tree.
// 7. It initializes the `diameter` to 0 and then calls the `height` helper function on the `root` node to calculate the height of the binary tree and update the `diameter`.
// 8. Finally, the function returns the calculated diameter of the binary tree.