
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0)
        {
            return head;
        }

        ListNode* temp = head;

        int count = 1;

        while(temp->next!=NULL)
        {
            count++;
            temp = temp->next;
        }


        // now join the last pointer to head i.e make it circular

        temp->next = head;

        // make k in range

        k = k % count;

        // now we have to find the point of rotation..

        k = count - k;

        while(k--)
        {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
        
    }
};