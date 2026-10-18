https://leetcode.com/problems/unique-paths/


class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>>dp(m,vector<int>(n,0));
        return solve(m-1,n-1,dp);
        
    }
    
    int solve(int m,int n,vector<vector<int>>&dp)
    {
        if(m<0)
            return 0;
        if(n<0)
            return 0;
        if(m==0)
            return 1;
        if(n==0)
            return 1;
        if(dp[m][n]!=0)
            return dp[m][n];
        
        return dp[m][n]=solve(m-1,n,dp)+solve(m,n-1,dp);
    }
};
--------------------------------------------------------------
DP

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<long long int>>dp(m+1,vector<long long int>(n+1,1));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
    
    
};
-------------------------------------------------------
One indexed DP

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<long long int>>dp(m+1,vector<long long int>(n+1,1));
        
        for(int i=2;i<=m;i++)
        {
            for(int j=2;j<=n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
        
    }
    
    
};
---------------------------------------------------------
Optimised:

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        vector<long long int>prev(n+1,1);
        vector<long long int> curr(n+1,0);
        curr[0]=1;
        
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                curr[j]=prev[j]+curr[j-1];
            }
            swap(prev,curr);
            curr[0]=1;
        }
        return curr[n-1];
        
    }
    
    
};