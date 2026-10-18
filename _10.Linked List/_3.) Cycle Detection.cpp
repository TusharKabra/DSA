EXPLANATION

Floyd’s Cycle-Finding Algorithm // fast slow approach // 2 pointers // "tortoise and the hare algorithm"

Approach: This is the fastest method and has been described below:

Traverse linked list using two pointers.

Move one pointer(slow_p) by one and another pointer(fast_p) by two.

If these pointers meet at the same node then there is a loop. 
If pointers do not meet then linked list doesn’t have a loop



class Solution {
public:
    bool hasCycle(ListNode *head) 
	{
	
		// if head is NULL then return false;
        if(head == NULL)
            return false;
        
		// making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }
};