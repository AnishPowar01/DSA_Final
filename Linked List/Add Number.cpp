// In a question it is stated that digits are stored in reverse order so no need to reverse the linked list 
// If questions doesn't menstioned about the reverse order ... we have to reverse a linked list before addition. also reverse the ll before returning it
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();

        ListNode* temp  = dummy;


        int carry = 0;

        while(l1!=NULL || l2!=NULL || carry)
        {
            int sum = 0;

            if(l1!=NULL)
            {
                sum = sum + l1->val;

                l1 = l1->next;
            }

            if(l2!=NULL)
            {
                sum = sum + l2->val;

                l2 = l2->next;
            }

            sum += carry;

            carry = sum/10;

            ListNode* ans = new ListNode(sum%10);

            temp->next = ans;
            temp = temp->next;


        }


        return dummy->next;
    }
};