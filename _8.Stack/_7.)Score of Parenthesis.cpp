https://leetcode.com/problems/score-of-parentheses/

Stack Implementation:
Basic ALGO:
1.)First push a 0 to store final score on stack
2.)whenever a '(' push a 0 on the stack
3.)When a ')' arrives, you pop the top most element. If the top element was 0,
then simply add 1 to the new top node in the stack,otherwise multiply the value by 2 
and add it to the new top element.

----------------------------------------------------------------------------------------
int scoreOfParentheses(string S)
{
    stack<int> m_stack;
    m_stack.push(0); // to keep the total score (very imp detail as string is balanced)
	
    for(char c:S)
	{
        if(c=='(')
            m_stack.push(0); //When meets '(', just push a zero to stack
			
        else
		{
            int tmp=m_stack.top(); //  balance the last '(', it stored the score of inner parentheses
            m_stack.pop();
            int val=0;
            if(tmp>0) // not zero means inner parentheses exists and double it
                val=tmp*2;
            else // zero means no inner parentheses, just using 1
                val=1;
				
            m_stack.top()+=val; // pass the score of this level to parent parenthese
        }   
    }
    return m_stack.top();
}

-----------------------------------------------------------------------------

Optimal Soln:
Let's take a look how do we calculate the score on following examples:

()() => 1+1
(()()) => 2*(1+1)
((()())) => 2*2*(1+1)
((()(()))) => 2*2*(1+2*1)

We can see that any () in the string gives a score depending on its depth. 
If () is located on the higher possible level (depth=0), the score is simply a 1. 
If it's located deeper, we just multiply it by 2 as many times as its depth. 
The found score we can just add to the final result. Why can we do that? 
Remember that, for example, this expression 2*2*(1+1) can be expressed as 2*2+2*2. 
No matter how deep parenthesis, the final expression of score can be represented 
as a sum of () scores.

Time: O(N) - traversing
Space: O(1)
------------------------------------------------------------------------
class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0, res = 0;
        char prev = '(';
        
        for (const char &ch: s) {
            if (ch == '(')
                depth++;
            else {
                depth--;
                if (prev == '(')
                    res += pow(2, depth);
            }
            
            prev = ch;
        }
        
        return res;
    }
};