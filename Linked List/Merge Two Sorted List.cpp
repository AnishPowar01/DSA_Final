
class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else
        {
             l2->next = merge(l1, l2->next);
            return l2;
        }
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        return merge(list1,list2);
        
    }
};