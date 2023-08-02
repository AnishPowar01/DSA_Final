class Solution {
public:
    void solve(TreeNode*r1)
    {
        if(!r1)
        {
            return;
        }

        swap(r1->left, r1->right);

        solve(r1->left);

        solve(r1->right);
    }
    TreeNode* invertTree(TreeNode* root) {
         
         if(root == NULL) return NULL;
        
        solve(root);
        return root;
    }
};