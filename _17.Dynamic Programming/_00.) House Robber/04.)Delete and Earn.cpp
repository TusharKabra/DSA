https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        
        int n=nums.size();
        vector<int>sum(10001,0);
        vector<int>dp(10001,0);
        for(int i=0;i<n;i++)
        {
            sum[nums[i]]+=nums[i];
        }
        
        dp[0]=sum[0];
        dp[1]=max(sum[0],sum[1]);
        
        for(int i=2;i<10001;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+sum[i]);
        }
        
        return dp[10000];
        
    }
};