
// Approach 1
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        set<ListNode*> st;

        ListNode* temp = head;

        while(temp!=NULL)
        {
            if(st.find(temp)!=st.end())
            {
                return temp;
            }

            st.insert(temp);

            temp = temp->next;
        }


        return NULL;
        
    }
};

// Approach 2 :

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) break;
        }

        if(fast==NULL || fast->next == NULL)  
        return NULL;

        ListNode* start = head;
        ListNode* Cycle_begins = slow;

        while(start!=Cycle_begins)
        {
            start = start->next;
            Cycle_begins = Cycle_begins->next;
        }

        return Cycle_begins;
        
    }
};