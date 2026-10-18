https://leetcode.com/problems/edit-distance/


Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
--------------------------------------------------------------------------------------------
Recursion

class Solution 
{
public:
    int solve(string &word1,string &word2,int i,int j)
    {
        
        if(i<0&&j<0)
            return 0;
        if(i<0)
            return j+1;  //0 based indexing so index j means j+1 char left to be inserted in string1 to make it equal to string2
        if(j<0)
            return i+1;   //i+1 char to be deleted in s1 to make it equal to s2
        if(word1[i]==word2[j])
        {
            return 0+solve(word1,word2,i-1,j-1);
        }
        
        int remove=1+solve(word1,word2,i-1,j);
        int insert=1+solve(word1,word2,i,j-1);
        int replace=1+solve(word1,word2,i-1,j-1);
        return min(min(remove,insert),replace);

    }
    int minDistance(string word1, string word2) 
    {
        int n=word1.length();
        int m=word2.length();
        return solve(word1,word2,n-1,m-1);
        
        
    }
};
----------------------------------------------------------------------------------
MEMOIZATION

class Solution 
{
public:
    int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp)
    {
        
        if(i<0&&j<0)
            return 0;
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]==word2[j])
        {
            dp[i][j]=0+solve(word1,word2,i-1,j-1,dp);
        }
        
       
        else
            dp[i][j]=1+min(min(solve(word1,word2,i-1,j,dp),solve(word1,word2,i,j-1,dp)),solve(word1,word2,i-1,j-1,dp));
                           
            return dp[i][j];
        
        
        
    }
    int minDistance(string word1, string word2) 
    {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(word1,word2,n-1,m-1,dp);
        
        
    }
};

---------------------------------------------------------------------
DP

//Convert to 1 based indexing
class Solution {
public:
    
    int minDistance(string word1, string word2) 
    {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
        
        return dp[n][m];
    }
};

-----------------------------------------------------------------------
Space Optimised

class Solution {
public:
    
    int minDistance(string word1, string word2) 
    {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<int>prev(m+1,0);
        vector<int>curr(m+1,0);
        for(int i=0;i<=m;i++)
        {
            prev[i]=i;
        }
        curr[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                    curr[j]=prev[j-1];
                else
                curr[j]=1+min(min(prev[j],curr[j-1]),prev[j-1]);
            }
            swap(curr,prev);
            curr[0]=i+1;
        }
        
        return prev[m];
    }
};