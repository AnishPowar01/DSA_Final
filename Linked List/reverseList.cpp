// Approach 1 : Recursion

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        if(head->next == NULL)
        {
            return head;
        }

        ListNode* temp = reverse(head->next);

        head->next->next = head;
        head->next = NULL;

        return temp;
    }
    ListNode* reverseList(ListNode* head) {
          if(head == NULL)
            return NULL;
        return reverse(head);
        
    }
};


// Approach 2 : Iterative

class Solution {
    public:

     ListNode* reverseList(ListNode* head) 
     {
         if(head == NULL || head->next == NULL)
         {
             return head;
         }


         ListNode* prev = NULL;
         ListNode* curr = head;
         ListNode* nextNode = NULL;


         while(curr!=NULL)
         {
             nextNode = curr -> next;
             curr->next = prev;
             prev = curr;
             curr = nextNode;
         }

         return prev;
     }
};