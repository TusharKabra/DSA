https://leetcode.com/problems/rotate-list/
OBSERVATION and ALGO

1. Can convert the list to circular list so that it is easy to rotate
2. The tail node would be the (len-k)th node
3.)k=k%c where k is no. of rotations and c is the length of the linked list.

Procedure:
1.)Store the head in head pointer 
2.)Use a pointer temp to move through the list and store the length of the list.
3.)Using temp->next, connect the last node to the head node, making the list circular.
4.)Move till the len-k node. This is the new tail node.
5.)The node following this is our new head node.
6.)Cut the connection between the new head and the tail node.
---------------------------------------------------------------------------------------

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        ListNode* temp=head;
        if(head==NULL)
            return head;
        
        int c=1;//for storing the lenght of the linked list
        
        //count the number of nodes as well as position the 
        //tail(temp) pointer to the last node
        
        while(temp->next!=NULL) 
        {
            c++;
            temp=temp->next;
        }
        
        temp->next=head;//making the list circular;
        
        k=k%c;
        
        if(k>0)
        {
            for(int i=0;i<c-k;i++)// the tail node is the (len-k)-th node
            {
                temp=temp->next;
            }
        }
        
        ListNode* newHead=temp->next; //Newhead 
		
        temp->next=NULL; //converting the circular list back to normal;
        
        
        return newHead;
        
    }
};