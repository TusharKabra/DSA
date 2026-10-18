https://leetcode.com/problems/add-two-numbers-ii/

Input: 
l1 =    [7,2,4,3], 
l2 =      [5,6,4]
Output: [7,8,0,7]

Procedure: Same as Add Two No.s but here we use stack.
----------------------------------------------
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        stack<int>st1;
        stack<int>st2;
        
        ListNode* temp=NULL;
        while(l1!=NULL)
        {
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            st2.push(l2->val);
            l2=l2->next;
        }
        int carry=0;
        while(!st1.empty()||!st2.empty())
        {
            int sum=0;
            if(!st1.empty())
            {
                sum+=st1.top();
                st1.pop();
            }
            if(!st2.empty())
            {
                sum+=st2.top();
                st2.pop();
            }
            sum+=carry;
            ListNode* node=new ListNode(sum%10);
			
            node->next=temp;   //each time point the current node to temp and then make temp equal to the node;
            temp=node;
            carry=sum/10;

        }
        if(carry==0)
            return temp;
        else
        {
            ListNode* node=new ListNode(1);
            node->next=temp;
            return node;
            
        }

    }
};