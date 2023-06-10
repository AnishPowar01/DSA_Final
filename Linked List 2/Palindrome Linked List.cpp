// Approach : Use stack and compare
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        stack<int> st;

        ListNode* temp = head;

        while(temp!=NULL)
        {
            st.push(temp->val);
            temp = temp->next;
        }

 
            while(!st.empty())
            {
                if(head->val != st.top())
                {
                    return false;
                }

                st.pop();

                head = head->next;
            }

            return 1;
            
    
        
    }
};