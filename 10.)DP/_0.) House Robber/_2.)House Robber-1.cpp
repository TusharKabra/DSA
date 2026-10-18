
https://leetcode.com/problems/house-robber/

MEMOIZATION-

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n,-1);
        
        return solve(nums,dp,n-1);
        
    }
    
    int solve(vector<int>& nums,vector<int>& dp,int i)
    {
        int n=nums.size();
        if(i<0)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        else
            return dp[i]=max(solve(nums,dp,i-2)+nums[i],solve(nums,dp,i-1));
        
    }
};

============================================================

DP

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        if(nums.size()>1)
        {
            dp[1]=max(nums[0],nums[1]);
        }
        for(int i=2;i<n;i++)
        {
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
        
        
    }
    
};