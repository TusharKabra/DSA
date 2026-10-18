https://leetcode.com/problems/longest-palindromic-subsequence/ 

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by 
deleting some or no elements without changing the order of the remaining elements.

 
Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".


-------------------------------------------------------------------------

Solution:
Basically the LCS of string and its reverse


class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        string x=s;
        reverse(x.begin(),x.end());
        int n=x.length();
        return LCS(s,x,s.length(),x.length());
        
        
    }
    
    int LCS(string s,string x,int n,int m)
    {
        if(n==0||m==0)
            return 0;
        
        if(s[n-1]==x[m-1])
            return 1+LCS(s,x,n-1,m-1);
        
        return max(LCS(s,x,n-1,m),LCS(s,x,n,m-1));
        
    }
};

------------------------------------------------------------------
Memoization
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        string x=s;
        reverse(x.begin(),x.end());
        int n=x.length();
        int m=n;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return LCS(s,x,s.length(),x.length(),dp);
        
        
    }
    
    int LCS(string s,string x,int n,int m,vector<vector<int>>&dp)
    {
        if(n==0||m==0)
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(s[n-1]==x[m-1])
            return dp[n][m]=1+LCS(s,x,n-1,m-1,dp);
        
        return dp[n][m]=max(LCS(s,x,n-1,m,dp),LCS(s,x,n,m-1,dp));
        
    }
};
------------------------------------------------------------------
DP
class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {
        string x=s;
        reverse(x.begin(),x.end());
        int l1=x.length();
        int l2=l1;
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int n=1;n<=s.length();n++)
        {
            for(int m=1;m<=x.length();m++)
            {
                if(s[n-1]==x[m-1])
                dp[n][m]=1+dp[n-1][m-1];
                else
                dp[n][m]=max(dp[n-1][m],dp[n][m-1]);
        
            }
        }
        return dp[s.length()][x.length()];
    }
};