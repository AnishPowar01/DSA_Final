class Solution {
public:
    // Function to find the lowest common ancestor (LCA) of two nodes 'p' and 'q' in a binary search tree (BST).
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If both 'p' and 'q' are smaller than the current node's value, their LCA lies in the left subtree.
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        // If both 'p' and 'q' are larger than the current node's value, their LCA lies in the right subtree.
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        // If the above conditions are not met, it means 'p' and 'q' are on different sides of the current node, 
        // and the current node is their lowest common ancestor (LCA).
        else
            return root;
    }
};
