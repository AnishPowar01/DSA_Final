class Solution {
public:
    // Helper function to check if the given subtree is a valid BST with values within the given range.
    bool is_bst(TreeNode* root, long mini, long maxi) {
        if (root == NULL)
            return true; // If the subtree is empty, it is a valid BST.

        if (root->val >= maxi || root->val <= mini)
            return false; // If the current node's value is outside the valid range, it's not a valid BST.

        // Check if the left and right subtrees are valid BSTs, with updated ranges for the right and left subtrees, respectively.
        return is_bst(root->left, mini, root->val) && is_bst(root->right, root->val, maxi);
    }

    // Main function to check if the entire binary tree is a valid BST.
    bool isValidBST(TreeNode* root) {
        // Use LONG_MIN and LONG_MAX as initial minimum and maximum values to handle edge cases where the tree contains INT_MIN or INT_MAX.
        return is_bst(root, LONG_MIN, LONG_MAX);
    }
};


// Approach 2

class Solution {
public:


    bool isSorted(vector<int>&ans)
    {
        for(int i = 1; i<ans.size(); i++)
        {
            if(ans[i-1]>=ans[i])
            {
                return false;
            }
        }


        return true;
    }
    void MakeVector(TreeNode* root,vector<int>&ans)
    {
        if(root == NULL)
        {
            return;
        }

        MakeVector(root->left,ans);
        ans.push_back(root->val);
        MakeVector(root->right,ans);
    }
    bool isValidBST(TreeNode* root) {

        vector<int> ans;

        MakeVector(root, ans);

        return isSorted(ans);

    }
};