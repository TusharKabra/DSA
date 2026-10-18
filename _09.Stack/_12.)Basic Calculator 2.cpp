


ALGO:
Initialise sign as '+' (Not 1 as there are 4 operators now)
If it is a + sign:push curr
If it is a - sign: push -curr
if it is *: pop out the top elemtn multiply with the curr and then push back
if it is /: pop out the top elemtn divide with the curr and then push back




class Solution {
public:
    int calculate(string s) 
    {
        int n=s.length();
        stack<int>st;
        char sign='+'; //since now four operators are there
        int curr=0;
        long long int res=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
                curr=10*curr+(s[i]-'0');
            else if(s[i]==' ')
                continue;
            
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
            {
                if(sign=='+')
                    st.push(curr);
                
                else if(sign=='-')
                    st.push(curr*(-1));
                
                else if(sign=='*')
                {
                    int x=st.top();
                    st.pop();
                    st.push(x*curr);
                }
                else if(sign=='/')
                {
                    int x=st.top();
                    st.pop();
                    st.push(x/curr);
                }
                
                 curr=0;
                 sign=s[i];
            }
           
        }
        
		if(sign=='+')
			st.push(curr);
		
		else if(sign=='-')
			st.push(curr*(-1));
		
		else if(sign=='*')
		{
			int x=st.top();
			st.pop();
			st.push(x*curr);
		}
		else if(sign=='/')
		{
			int x=st.top();
			st.pop();
			st.push(x/curr);
		}
                
        
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
        
    }
};


----------------------------------------------------------------------
Slight Optimisation:
To avoid the curr!=0 case just append  a '+' to the last of the string. 
This will add the curr on to the stack

class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> stk; 
        
        long long int ans = 0, curr = 0;
        char sign = '+'; //to store the previously encountered sign
        
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])) curr = curr*10 + (s[i]-'0'); //keep forming the number, until you encounter an operator
            
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                
                if(sign == '+') stk.push(curr); //'Cause it has to added to the ans
            
                else if(sign == '-') stk.push(curr*(-1)); //'Cause it has to be subtracted from ans
                
                else if(sign == '*'){
                    int num = stk.top(); stk.pop();  //Pop the top of the stack
                    stk.push(num*curr); //Multiply it with the current value & push the result into stack
                }
                
                else if(sign == '/'){
                    int num = stk.top();stk.pop(); 
                    stk.push(num/curr);  //Divide it with curr value & push it into the stack
                }
                
                curr = 0; 
                sign = s[i]; 
            }
            
        }
        
        while(stk.size()){
            ans += stk.top(); stk.pop();
        }
            
        return ans;    
    }
};