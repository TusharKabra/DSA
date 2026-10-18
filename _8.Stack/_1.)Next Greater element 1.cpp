https://leetcode.com/problems/next-greater-element-i/

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

============================================================================================
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2
--------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int,int>mp;
        int n=nums2.size();
        
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums2[i]>st.top())
            {
                st.pop();
            }
            if(!st.empty())
            {
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
            if(st.empty())
            {
                st.push(nums2[i]);
                mp[nums2[i]]=-1;
            }
        }
		
//storing the answer	
	
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            ans[i]=mp[nums1[i]];
        }
        return ans;
        
            
        
    }
};