https://leetcode.com/problems/reorder-list/
Detailed Explan: https://www.youtube.com/watch?v=S5bfdUTrKLM


Approach:
1.)Find the middle node.If two middle nodes(even length)then find the first one.
2.)Reverse the second Half of the linked list
3.)Merge two halfs.The second half is either equal or smaller than the first half.

----------------------------------------------------------------------------
class Solution {
public:
    void reorderList(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)
            return;
        
        //Find the middle node.If two middle nodes(even length) then find the first one.
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //Reverse the second Half of the linked list
        
        ListNode* prev=NULL;
        ListNode* curr=slow->next;
        ListNode* next=NULL;
        slow->next=NULL;
        
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        //Merge two halfs:
        //The second half is either equal or smaller than the
        //first half.
        
        ListNode* first=head;
        ListNode* second=prev;
        while(second)
        {
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            
            first->next=second;
            second->next=temp1;
            
            first=temp1;
            second=temp2;
        }
        
        
        
        
    }
};