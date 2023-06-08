
class Solution {
    private:
    int length(ListNode* head)
    {
        int counter = 0;
        ListNode* temp = head;

        while(temp!=NULL)
        {
            counter++;
            temp = temp->next;
        }


        return counter;
    }
    public:
    ListNode* removeNthFromEnd(ListNode* head, int &n) 
    {
        if(head == NULL)
        {
            return head;
        }


        int len = length(head);

        int pos_from_start = (len - n);

        
        ListNode* temp = head;

        if(pos_from_start == 0)
        {
            return head->next;
        }

        while(pos_from_start != 1)
        {
            temp = temp->next;
            pos_from_start--;
        }


        ListNode * node = temp->next;
        temp->next = node->next;
        node->next = NULL;
        delete node;



        return head;


    }

};

