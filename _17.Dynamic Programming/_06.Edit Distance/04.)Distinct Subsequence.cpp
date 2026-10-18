https://leetcode.com/problems/distinct-subsequences/


Given two strings s and t, return the number of distinct subsequences of s which equals t.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
--------------------------------------------------------------------------------


//f(i,j)= No. of distinct subsequences of  t[0..j] in s[0..i].
Recursion:

class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        int n=s.length();
        int m=t.length();
        return solve(s,t,n-1,m-1);
        
    }
    
    int solve(string &s, string &t,int i,int j)
    {
        if(j<0)
            return 1;
        if(i<0&&j>=0)
            return 0;
        
        if(s[i]==t[j])  /if characters are matching
        {
            return solve(s,t,i-1,j-1)+solve(s,t,i-1,j);    //When char matches we choose to either take that 
			                                               //char or we choose to take the same char from other location in string s
        }
        else
           return solve(s,t,i-1,j);
        
            
    }
};
---------------------------------------------------------------------------
MEMOIZATION:

class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
        
    }
    
    int solve(string &s, string &t,int i,int j,vector<vector<int>>&dp)
    {
        if(j<0)
            return 1;
        if(i<0&&j>=0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==t[j])
        {
            return dp[i][j]=solve(s,t,i-1,j-1,dp)+solve(s,t,i-1,j,dp);
        }
        else
           return dp[i][j]=solve(s,t,i-1,j,dp);
        
            
    }
};
---------------------------------------------------------------------------------
DP
//Surprisingly gave runtime error. Use double hack


class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n=s.length();
        int m=t.length();
        vector<vector<long long int>>dp(n+1,vector<long long int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=m;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][m];
        
        
    }
    
    
};

Hack Solution:
class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int n=s.length();
        int m=t.length();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=m;i++)
        {
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return (int)dp[n][m];
        
        
    }
    
    
};