class Solution {
public:
    int sum = 0;

    int solve(TreeNode* root) {
        
        if (root == NULL) {
            return 0;
        }

        //  calculate the sum of nodes in the left and right subtrees.
        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        // Calculate the absolute difference between the sums of left and right subtrees and update the global sum.
        sum += abs(leftSum - rightSum);

        // Return the sum of nodes in the current subtree, including the root node.
        return root->val + leftSum + rightSum;
    }

    
    int findTilt(TreeNode* root) {
       
        solve(root);
        return sum;
    }
};
