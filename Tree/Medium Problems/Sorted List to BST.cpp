class Solution {
public:
    TreeNode* solve(vector<int>&ans, int i, int j)
    {
        if(i>=j) return NULL;

        if(i+1 == j) return new TreeNode(ans[i]);

        int mid = i + (j-i)/2;

        TreeNode* temp = new TreeNode();
        temp->val = ans[mid];

        temp->left = solve(ans,i,mid);

        temp->right = solve(ans,mid+1,j);


        return temp;
    }
    TreeNode* sortedListToBST(ListNode* head) {

        vector<int>ans;

        if(head == NULL) return NULL;

        while(head!=NULL)
        {
            ans.push_back(head->val);

            head = head->next;
        }

        return solve(ans,0,ans.size());        
    }
};