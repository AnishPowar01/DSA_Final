// Approach 1 : tortoise and the hare algorithm
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
       
       return slow;
        
    }
};

// Approach 2 : Find length and then return lenght/2 th node;

class Solution {
    
    public:
     ListNode* middleNode(ListNode* head) {

         ListNode* temp = head;
         int counter = 0;

         while(temp!=NULL)
         {

            temp = temp->next;
            counter++;
             
         }

         int mid = counter/2;

         temp = head;

         while(mid--)
         {

             temp = temp->next;
             
         }

         if(mid&1)
         {
             return temp;
         }

         return temp->next;
     }

};