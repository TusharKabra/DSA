

https://leetcode.com/problems/partition-equal-subset-sum/

Partition problem is to determine whether a given set can be partitioned into
two subsets such that the sum of elements in both subsets is the same. 

1.Recursive


class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        if(sum%2!=0)
            return false;
        
        return solve(nums,sum/2,n-1);
        
    }
    
    bool solve(vector<int>&nums,int target,int i)
    {
        if(i<0)
            return false;
        if(target==0)
            return true;
        
        if(nums[i]>target)
            return solve(nums,target,i-1);
        
        else 
            return solve(nums,target,i-1)||solve(nums,target-nums[i],i-1);
    }
};
--------------------------------------------------------------------------------

2.)Memoization

//     bool solve(long int sum,vector<int>&num,int n,vector<vector<int>>&dp)
//     {
//         if(sum==0)
//             return true;
//         if(n<=0)
//             return false;
//         if(dp[n-1][sum]!=-1)
//             return dp[n-1][sum];
//         if(num[n-1]>sum)
//             return dp[n-1][sum]=solve(sum,num,n-1,dp);
        
//         else
//             return dp[n-1][sum]=solve(sum-num[n-1],num,n-1,dp)||solve(sum,num,n-1,dp);
        
//     }

-----------------------------------------------------------------------------------

3.)DP Soln:


class Solution {
public:
    
//     bool solve(long int sum,vector<int>&num,int n,vector<vector<int>>&dp)
//     {
//         if(sum==0)
//             return true;
//         if(n<=0)
//             return false;
//         if(dp[n-1][sum]!=-1)
//             return dp[n-1][sum];
//         if(num[n-1]>sum)
//             return dp[n-1][sum]=solve(sum,num,n-1,dp);
        
//         else
//             return dp[n-1][sum]=solve(sum-num[n-1],num,n-1,dp)||solve(sum,num,n-1,dp);
        
//     }
    bool canPartition(vector<int>& nums) 
    {
        long int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=sum/2;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum/2;j++)
            {
                if(nums[i-1]>j)
                   dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][sum/2];
    }
};

--------------------------------------------------------------------------------------

