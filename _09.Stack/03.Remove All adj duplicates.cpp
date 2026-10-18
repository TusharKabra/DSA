
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        int n=s.length();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&st.top().second==k)
            {
                int m=k;
                while(m>0)
                {
                    st.pop();
                    m--;
                }
                
            }
            if(st.empty())
            {
                st.push({s[i],1});
            }
            else 
            {
                if(st.top().first==s[i])
                {
                    st.push({s[i],st.top().second+1});
                }
                else
                {
                    st.push({s[i],1});
                }
            }    
        }
        while(!st.empty()&&st.top().second==k)      //Ex aaa and k=3.
        {
            int m=k;
            while(m>0)
            {
                st.pop();
                m--;
            }

        }
        string res="";
        while(!st.empty())
        {
            res+=st.top().first;
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};