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

//ALGORITHM FOR O(1) Space
//first count the nodes then move to the second half of the list, 
then reverse the second half of the list using the iterative three pointer method. 
then again compare the first and second half of the linked list for pallindrome and 
store the result. Restore the second half back and then return the list
        


class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode* firsthalfend=endOfFirstHalf(head);
        ListNode* secondhalfstart=reverse(firsthalfend->next);
        
        ListNode* p1=head;
        ListNode* p2=secondhalfstart;
        
        // Check whether or not there is a palindrome.
       
        bool result = true;
        while (result==true && p2 != NULL) 
        {
            if (p1->val != p2->val) 
                result = false;
            
            p1 = p1->next;
            p2 = p2->next;
        }        
        // Restore the list and return the result.
        firsthalfend->next = reverse(secondhalfstart);
        return result;
    }
    
    //Finds the end of first half using the slow fast pointer tech
    ListNode* endOfFirstHalf(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    //reverse the second half
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            
            curr->next=prev;
            
            prev=curr;
            curr=next;
        }
        return prev;
    }
};