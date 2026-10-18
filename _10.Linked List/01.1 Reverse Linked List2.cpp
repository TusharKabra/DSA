https://leetcode.com/problems/reverse-linked-list-ii/


Detailed Explan:
https://www.youtube.com/watch?v=RF_M9tX4Eag

Use Dummy node:
Reason: Helps solve the edge case of reversing the entire linked list
Also helps deal with cases that have L=1. In such cases our original head node will change.

Procedure:
1.)Reach the leftmost node and store the node just before this.Need to take 
   L-1 steps to reach here.(1 based indexing of L and R).

2.)ReverseList. We are reversing R-L+1 nodes.

3.)Update Pointers
-----------------------------------------------------------------------------------------------------

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* dummy= new ListNode(0);
        dummy->next=head;
        
        
        ListNode* temp=dummy;
        ListNode* leftNode=head;
        //Reach the leftmost node and store the node just before this.
        //Need to take L-1 steps to reach here.(1 based indexing of L and R)
        
        for(int i=1;i<=left-1;i++)
        {
            temp=temp->next;
            leftNode=leftNode->next;
        }
        
        //ReverseList. We are reversing R-L+1 nodes.
        
        ListNode* prev=NULL;
        ListNode* curr=leftNode;
        ListNode* next=NULL;
        for(int i=1;i<=right-left+1;i++)
        {
            
            next=curr->next;
            
            curr->next=prev;
            
            prev=curr;
            curr=next;
        }
        
        //Update Pointers
        temp->next->next=curr; //curr is the node after right
        temp->next=prev; //prev is the right node
        
        return dummy->next;
    }
};