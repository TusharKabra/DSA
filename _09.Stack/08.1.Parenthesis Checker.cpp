Question:
The function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int n=x.size();
        stack<char>st;
        
        for(int i=0;i<n;i++)
        {
            if(!st.empty())
            {
                if(x[i]=='['||x[i]=='{'||x[i]=='(')
                {
                    st.push(x[i]);
                }
                else
                {
                    if(x[i]==']'&&st.top()!='['||x[i]=='}'&&st.top()!='{'||x[i]==')'&&st.top()!='(')
                    {
                        return false;
                    }
                    else
                    st.pop();
                }
                
            }
            else
            {
                if(x[i]=='['||x[i]=='{'||x[i]=='(')
                {
                    st.push(x[i]);
                }
                else
                return false;
            }
        }
		
        if(st.size()>0) //Using this condition for the case of more open brackets than closed.
        return false;
        
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends