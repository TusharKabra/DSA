https://leetcode.com/problems/middle-of-the-linked-list/ 

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.


class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
        if(c%2==1)
            c=(c+1)/2;
        else
            c=(c+2)/2;
        
        cout<<c<<endl;
        while(c-1>0)
        {
            c--;
            head=head->next;
        }
        return head;
        
        
        
    }
};
----------------------------------------------------
Slow -fast pointer method
T.C=O(N/2)

ListNode* middleNode(ListNode* head) 
{
        ListNode *slow = head; 
		ListNode *fast = head;
        while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
        return slow;
}