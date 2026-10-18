Q)FIND ENTRY POINT OF CYCLE


//BRUTE FORCE

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        map<ListNode*,int>mp;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            mp[temp]++;
            if(mp[temp]>1)
                return temp;
            temp=temp->next;
        }
        return NULL;
        
    }
};


----------------------------------------------

OPTIMAL SOLN:

Refer this for detailed Explan:
https://leetcode.com/problems/linked-list-cycle-ii/discuss/1701055/JavaC%2B%2BPython-best-explanation-ever-happen's-for-this-problem 

MATHS LOGIC
What is the distance fast moved? What is the distance slow moved? And their relationship?

x1+x2

x1+n(x2+x3)+x2

x1+n(x2+x3)+x2=2(x1+x2)

Here n is an integer greater than or equal to 0.
And x2+x3 is the length of the loop.
Then we can get:

x1=(n-1)x2+nx3
x1=(n-1)x2+(n-1)x3+x3
x1=(n-1)C+x3 where C is the cycle length(X2+x3)
------------------------------------------------------------------
ALGO

1st move the fast pointer at 2X and slow pointer at 1X. 
If fast or fast->next becomes NULL no cycle
Otherwise fast and slow will eventually meet.
After they have met reset the slow pointer to head and then move both the pointers at 1X
Now the meeting point of the two nodes will be the entry point of cycle

class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
	{
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL)
		{
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
			{
                slow = head;
                while(slow != fast)
				{
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

