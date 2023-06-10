/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Approach : 
// step 1 :  Reverse the first k group
// Step2 : apply recursion for remaining 
// step3 : return ans

// but by using above algo... it also reverse the group which have size less than k
// so for that we have to just modify the code as follows : 
class Solution {
private:
    ListNode* helper(ListNode* head, int size, int k)
    {
        if(head == NULL || size<k) return head;     // modified line

        // Reverse first k node;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        int count = 0;

        while(curr!=NULL && count < k)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            count++;
        }

           if(nextNode!=NULL)
        {

            head->next = helper(nextNode,size-k,k);

        }

        return prev;

    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head == NULL)
        {
            return NULL;
        }

        int size = 0;

        ListNode* temp = head;

        while(temp!=NULL)
        {
            size++;
            temp = temp->next;
        }

        // Reverse first k node;

        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // ListNode* nextNode = NULL;
        // int count = 0;

        // while(curr!=NULL && count < k)
        // {
        //     nextNode = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nextNode;
        //     count++;
        // }

        // if(nextNode!=NULL)
        // {

        //     head->next = reverseKGroup(nextNode,k);

        // }

        return helper(head,size,k);
        
    }
};