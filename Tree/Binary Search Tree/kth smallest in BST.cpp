
class Solution
{
public:
    int count = 0;
    int ans = INT_MAX;

    void inorder(TreeNode *root, int k)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, k);
        count++;

        if (count == k)
        {
            ans = root->val;
            return;
        }

        inorder(root->right, k);
    }
    int kthSmallest(TreeNode *root, int k)
    {

        inorder(root, k);

        return ans;
    }
};