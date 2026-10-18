https://leetcode.com/problems/intersection-of-two-linked-lists/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        ListNode* temp3=headA;
        ListNode* temp4=headB;
        
        int c1=0;
        int c2=0;
        while(temp1!=NULL)
        {
            c1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            c2++;
            temp2=temp2->next;
        }
        while(c1>c2&&temp3!=NULL)
        {
            c1--;
            temp3=temp3->next;
        }
        while(c2>c1&&temp4!=NULL)
        {
            c2--;
            temp4=temp4->next;
        }
        while(temp3!=NULL&&temp4!=NULL)
        {
            if(temp3==temp4)
                return temp3;
            
            else
                temp3=temp3->next;temp4=temp4->next;
            
        }
        return NULL;
        
        
        
    }
};