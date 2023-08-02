
    //  * Definition for a binary tree node.
    //  * struct TreeNode {
    //  *     int val;
    //  *     TreeNode *left;
    //  *     TreeNode *right;
    //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    //  * };
    //  */
    class Solution
{
public:
    // Helper function to check if the binary tree is balanced.
    // It returns the height of the tree if it is balanced, otherwise returns -1.
    int solve(TreeNode *root)
    {
        // Base case: If the root is NULL (empty tree), it is balanced with height 1.
        if (root == NULL)
        {
            return 1;
        }

        // Recursively calculate the height of the left subtree.
        int leftHeight = solve(root->left);

        // If the left subtree is not balanced (height is -1), return -1.
        if (leftHeight == -1)
        {
            return -1;
        }

        // Recursively calculate the height of the right subtree.
        int rightHeight = solve(root->right);

        // If the right subtree is not balanced (height is -1), return -1.
        if (rightHeight == -1)
        {
            return -1;
        }

        // If the difference between the heights of left and right subtrees is greater than 1,
        // the current subtree is not balanced, so return -1.
        if (abs(rightHeight - leftHeight) > 1)
        {
            return -1;
        }

        // If the current subtree is balanced, return its height by adding 1 to the maximum of the left and right heights.
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to check if the binary tree is balanced or not.
    bool isBalanced(TreeNode *root)
    {
        // Call the helper function to check if the binary tree is balanced.
        // If the helper function returns -1, it means the tree is not balanced, otherwise, it is balanced.
        return solve(root) != -1;
    }
};

// Explanation:
// 1. The function `solve` is a helper function that checks if a binary tree is balanced and returns its height if it is balanced, otherwise, it returns -1.
// 2. The base case of the recursion is when the root is NULL, which indicates an empty tree. In this case, the tree is balanced, and its height is 1.
// 3. For a non-empty tree, the function recursively calculates the heights of the left and right subtrees by calling `solve` on the left and right child nodes, respectively.
// 4. If any of the subtrees is not balanced (height is -1), the current subtree is also not balanced, and the function returns -1.
// 5. If the difference between the heights of the left and right subtrees is greater than 1, the current subtree is not balanced, and the function returns -1.
// 6. If the current subtree is balanced, the function returns its height by adding 1 to the maximum of the left and right heights.
// 7. The `isBalanced` function is the main function that calls the `solve` helper function to check if the binary tree is balanced or not. If `solve` returns -1, it means the tree is not balanced, and the function returns `false`. Otherwise, it returns `true`, indicating that the tree is balanced.