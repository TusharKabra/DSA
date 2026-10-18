Prereq:LargestRectangle Histogram question

https://leetcode.com/problems/maximal-rectangle/ 

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        
        int m=matrix[0].size();
        int n=matrix.size();
        vector<int>x(m,0);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')   //must see whether a char 2d array is given or a no. 2D array is given
                    x[j]=0;
                else
                x[j]=x[j]+matrix[i][j]-'0';
            }
            
            mx=max(mx,largestRectangleArea(x));
        }
        return mx;
        
    }
    int largestRectangleArea(vector<int>&heights) 
    {
        int n=heights.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        stack<int>st;
        //right side
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&heights[i]<=heights[st.top()])
            {
                st.pop();
            }
            if(st.empty())
            {
                st.push(i);
                right[i]=n;
            }
            else
            {
                right[i]=st.top();
                st.push(i);
            }
        }
        
       
        //left side
        stack<int>st1;
        for(int i=0;i<n;i++)
        {
            while(!st1.empty()&&heights[i]<=heights[st1.top()])
            {
                st1.pop();
            }
            if(st1.empty())
            {
                st1.push(i);
                left[i]=0;
            }
            else
            {
                left[i]=st1.top()+1;
                st1.push(i);
                
            }
        }

        //Calculating the max value
        int mx=0;
        for(int i=0;i<n;i++)
        {
            int x=(abs(left[i]-right[i]))*(heights[i]);
            mx=max(mx,x);
        }
        return mx;
        
    }
};