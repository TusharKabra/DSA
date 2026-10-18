https://leetcode.com/problems/evaluate-reverse-polish-notation/

Reverse Polish Notation:
1.) To add 3 and 4 together, one would write 3 4 + rather than 3 + 4
2.) The expression written 3 − 4 + 5 in conventional notation would be 
written 3 4 − 5 + in reverse Polish notation
3.) 3 − (4 × 5):3 4 5 × −
4.)(3 − 4) × 5: 3 4 − 5 ×

--------------------------------------------------
Use stoi() for string to no. conversion. Ensure that no other operator is passed 
to stoi otherwise big debug mess
===================================================

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int>st;
        int n=tokens.size();
        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b+a);
                continue;
            }
            if(tokens[i]=="-")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b-a);
                continue;
            }
            if(tokens[i]=="*")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b*a);
                continue;
            }
            if(tokens[i]=="/")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                st.push(b/a);
                continue;
            }
            else
            {
                
                st.push(stoi(tokens[i]));
                
                
            }
            
        }
        return st.top();
        
    }
};