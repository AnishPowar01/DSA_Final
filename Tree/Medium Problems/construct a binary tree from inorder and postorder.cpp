lass Solution {
private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int posStart, int posEnd)
    {
        if(inStart > inEnd)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[posEnd]);


        int index = inStart;

        while(index < inorder.size())
        {
            if(inorder[index] == root->val)
            {
                break;
            }

            index++;
        }


        // find left  size

        int leftSize = index - inStart;
        int rightSize = inEnd - index;


        // recursive call to build root's left and right

        root->left = build(inorder, postorder,inStart, index-1, posStart, posStart + leftSize - 1);
        root->right = build(inorder, postorder,index+1, inEnd, posEnd-rightSize ,posEnd-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

         int n = inorder.size();
         int m = postorder.size();


         int inStart = 0;
         int inEnd = n-1;

         int posStart = 0;
         int posEnd = m-1;


         return build(inorder, postorder, inStart, inEnd, posStart, posEnd);
        
    }
};