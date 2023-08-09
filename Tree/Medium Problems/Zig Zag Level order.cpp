// 1) Approach 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        queue<TreeNode*>q;
        vector<vector<int>>ans;

        if(root == NULL)
        {
            return ans;
        }

        q.push(root);

        bool LTR = true;


        while(!q.empty())
        {
            int size = q.size();
            vector<int>level(size);


            for(int i = 0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                


                int index = (LTR) ? i : size - 1 - i;

                level[index] = node->val;


                if(node->left!=NULL)
                {
                    q.push(node->left);
                }

                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }

            ans.push_back(level);

            LTR = !LTR;

        }

        return ans;
        
    }
};


// Approach 2

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        queue<TreeNode*> q;

        if(root == NULL) return ans;

        bool LTR = true;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for(int i = 0; i<size; i++)
            {

                TreeNode*  temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left)
                {
                    q.push(temp->left);
                }

                if(temp->right)
                {
                    q.push(temp->right);
                }

            }
            if(!LTR)
            {
                reverse(level.begin(), level.end());
            }
            LTR = !LTR;
            ans.push_back(level);
        }

        return ans;
        
    }
};