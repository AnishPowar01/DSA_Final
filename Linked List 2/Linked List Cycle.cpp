/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach 1

class Solution{

    public:
    bool hasCycle(ListNode* head)
    {
        if(head == NULL) return false;

        unordered_map<ListNode*, int>mp;

        ListNode* temp = head;

        while(temp!=NULL)
        {
            if(mp.find(temp)!=mp.end())
            {

                return 1;
                
            }
             mp[temp]++;
    
            temp = temp->next;
        }

        return 0;
    }
};

// Approach 2
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        if(slow==fast)
        {
         return 1;
        }
        }

      

        return 0;

    }
};