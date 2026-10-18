https://www.geeksforgeeks.org/reverse-a-linked-list/ 

Initialize three pointers prev as NULL, curr as head and next as NULL.
Iterate through the linked list. 
In loop, do following. 

https://leetcode.com/problems/reverse-linked-list/ 

ALGO
ORDER:STORE THE NEXT NODE THEN REVERSE THE LINK OF CURRENT NODE THEN MOVE FORWARD

Before changing next of current, store next node 
next = curr->next

Now change next of current 
This is where actual reversing happens 
curr->next = prev 

Move prev and curr one step forward 
prev = curr 
curr = next


---------------------------------------------------------------------------------------------
ITERATIVE SOLUTION
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        // Initialize current, previous and next pointers
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
 
        while (current != NULL) 
        {
            // Store next
            next = current->next;
			
            // Reverse current node's pointer
            current->next = prev;
			
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
        
        
        
    }
};

-------------------------------------------------------------------------
Recursive Implementation-Slightly tricky(Watch Mycodeschool)

class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
	{
        if (!head || !(head -> next)) 
		{
            return head;
        }
		
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node;
    }
};


