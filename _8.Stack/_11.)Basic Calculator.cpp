https://leetcode.com/problems/basic-calculator/ 
Expression has +,-,(,)

----------------------------------------------------------------------
Tricks involved:
How to take two digit no?
How to deal with parenthesis?
------------------------------------------------------------------------
ALGO
Only 5 possible input we need to pay attention:

digit: it should be one digit from the current number
'+': number is over, we can add the previous number and start a new number
'-': same as above
'(': push the previous result and the sign into the stack, set result to 0, 
just calculate the new result within the parenthesis.
')': pop out the top two numbers from stack, first one is the sign before this 
pair of parenthesis, second is the temporary result before this pair of parenthesis. 
We add them together.


------------------------------------------------------------------------
class Solution 
{
public:
    int calculate(string s) 
    {
        int n=s.length(); 
        int sign=1;
        stack<int>st;
        int curr=0;   //current number
        int res=0;    
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                curr=curr*10+(s[i]-'0');
            }
            else if(s[i]=='+')
            {
                res+=sign*curr;
                curr=0;
                sign=1;
                
            }
            else if(s[i]=='-')
            {
                res+=sign*curr;
                curr=0;
                sign=-1;
                
            }
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
				
                res=0;  //reset the sign and result for the value in the parenthesis
                sign=1;  
                
            }
            else if(s[i]==')')
            {
                res+=sign*curr;   //this completes the within parenthesis result
                curr=0;
				
                res*=st.top();   //multiply by the sign before the parenthesis
                st.pop();
                res+=st.top();   //Add the result calculated before the parenthesis
                st.pop();
            }
            
        }
        if(curr!=0)                   //for simple cases like 1+2
            res+=sign*curr;
        
        return res;
        
    }
};
