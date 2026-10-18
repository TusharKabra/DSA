https://leetcode.com/problems/next-greater-element-ii/

Circular Array.
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
-----------------------------------------------------------------------------------
1st approach
Push indexes into stack in decreasing order for circular array

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n=nums.size();
        stack<int>st;
        
        for(int i=n-1;i>=0;i--)
        {
            st.push(i);
        }
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[i]>=nums[st.top()])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i]=nums[st.top()];
                st.push(i);
            }
            if(st.empty())
            {
                ans[i]=-1;
                st.push(i);
            }
            
        }
        
        return ans;
    }
};

----------------------------------------------------------
2nd Approach
Using modulus

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums[i%n])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                ans[i%n]=-1;
            }
            else
            {
                ans[i%n]=st.top();
            }
            st.push(nums[i%n]);
            
        }
       
        return ans;
    }
};