class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL)
        {
            return NULL;
        }

        if(root == p || root == q)
        {
            return root;
        }


        TreeNode* leftAns = lowestCommonAncestor(root->left, p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p,q);


        if(leftAns!= NULL && rightAns!=NULL)
        {
            return root;
        }
        else if(leftAns == NULL)
        {
            return rightAns;
        }
        else if(rightAns == NULL)
        {
            return leftAns;
        }
        else
        {
            return NULL;
        }
        
    }
};