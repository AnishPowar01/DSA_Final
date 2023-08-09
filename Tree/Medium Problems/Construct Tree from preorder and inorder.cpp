class Solution {
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int preStart, int preEnd) {
        if (inStart > inEnd) {
            return NULL; // Base case: If the inorder index range is invalid, return NULL (empty subtree).
        }

        // Create a new node with the value from the current position in the preorder array.
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the index of the current node's value in the inorder array to determine the left and right subtrees' boundaries.
        int index = inStart;
        while (index < inorder.size()) {
            if (inorder[index] == root->val) {
                break;
            }
            index++;
        }

        // Calculate the size of the left and right subtrees based on the found index.
        int leftSize = index - inStart;
        int rightSize = inEnd - index;

        // Recursively build the left and right subtrees.
        root->left = build(preorder, inorder, inStart, index - 1, preStart + 1, preStart + leftSize);
        root->right = build(preorder, inorder, index + 1, inEnd, preEnd - rightSize + 1, preEnd);

        return root; // Return the current root node of the subtree.
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();

        int inStart = 0;
        int inEnd = n - 1;

        int preStart = 0;
        int preEnd = m - 1;

        // Call the build function to construct the binary tree and return the root of the tree.
        return build(preorder, inorder, inStart, inEnd, preStart, preEnd);
    }
};
