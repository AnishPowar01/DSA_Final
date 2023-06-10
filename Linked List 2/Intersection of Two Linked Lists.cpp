/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // Approach 1 : O(m+n)

class Solution{
    int length(ListNode *headA)
    {
        ListNode* temp = headA;
        int count = 0;

        while(temp!=NULL)
        {
            temp = temp->next;
            count++;
        }

        return count;

    }
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
        {
            if(headA == NULL || headB == NULL) return NULL;

            ListNode* temp1 = headA;
            ListNode* temp2 = headB;

            // find the lentght of ll

            int l1 = length(headA);

            int l2 = length(headB);


            if(headA == headB)
            {
                return headA;
            }

            int ans = 0;


            if(l1 > l2)
            {
                ans = l1 - l2;

                while(ans--)
                {
                    temp1 = temp1->next;
                }


                while(temp1 != NULL || temp2!=NULL)
                {
                    if(temp1 == temp2)
                    {
                        return temp1;
                    }

                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }

            }
            else
            {
                ans = l2 - l1;

                while(ans--)
                {
                    temp2 = temp2->next;
                }


                while(temp1 != NULL || temp2!=NULL)
                {
                    if(temp1 == temp2)
                    {
                        return temp2;
                    }

                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }

            }

            return NULL;


        }

};

// Approach 2 : O(m+n)   two pointer
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1!=temp2)
        {
            if(temp1 == NULL)
            {
                temp1 = headB;
            }
            else
            {
                temp1 = temp1->next;
            }

            if(temp2 == NULL)
            {
                temp2 = headA;

            }

            else
            {
                temp2 = temp2->next;
            }
        }


        return temp1;

    }
};


// Approach 3 : O(m+n)
class Solution {

    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode*, int>mp;

        ListNode* temp1= headA;

        while(temp1!=NULL)
        {
            mp[temp1]++;
            temp1 = temp1->next;
        }

        temp1 = headB;

        while(temp1!=NULL)
        {
            if(mp[temp1] > 0)
            {
                return temp1;
            }

            temp1 = temp1->next;
        }

        return NULL;
    }

};