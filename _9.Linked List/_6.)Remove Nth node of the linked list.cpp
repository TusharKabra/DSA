https://leetcode.com/problems/remove-nth-node-from-end-of-list/ 

========================
-------L----------------
[---x-----][------n----]

--------L----------------
[------n------]
slow           fast
[-----x----][-----n------]


ALGO:
create a dummy node pointing at haed
Initially keep the slow and fast pointer at dummy node. Then move the fast pointer by n
Then simultaneously move the slow and fast pointer till fast->next becomes NULL
This algo also handles the base case of deleting the head node

---------------------------------------------------------------
Optimal Solution:

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();  //dummy node
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};

