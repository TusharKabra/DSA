https://leetcode.com/problems/largest-divisible-subset/ 

Given a set of distinct positive integers nums, return the largest 
subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.


Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
--------------------------------------------------------------------------

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>index(n);
        for(int i=0;i<n;i++)
        {
            index[i]=i;
        }
        int mx=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0&&1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    index[i]=j;
                }
            }
            mx=max(mx,dp[i]);
        }
        
       int i=n-1; 
       while(1)
       {
           if(dp[i]==mx)
               break;
           else
               i--;
       }
        vector<int>temp;
       while(i!=index[i])
       {
           temp.push_back(nums[i]);
           i=index[i];
       }
        temp.push_back(nums[i]);
        
        return temp;
        
        
    }
};