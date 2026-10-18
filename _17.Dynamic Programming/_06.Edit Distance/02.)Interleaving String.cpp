

Recursion:TLE

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int i=s1.length();
        int j=s2.length();
        int k=s3.length();
        if(i+j!=k)
            return false;
        return solve(s1,s2,s3,i,j,k);
        
    }
    bool solve(string &s1,string &s2,string &s3,int i,int j,int k)
    {
        if(i<=0&&j<=0&&k<=0)
            return true;
        
        if(i>0&&j>0&&s1[i-1]==s2[j-1]&&s2[j-1]==s3[k-1])
            return solve(s1,s2,s3,i-1,j,k-1)||solve(s1,s2,s3,i,j-1,k-1);
        
        else if(i>0&&s1[i-1]==s3[k-1])
           return (solve(s1,s2,s3,i-1,j,k-1));
                   
        else if(j>0&&s2[j-1]==s3[k-1])
           return solve(s1,s2,s3,i,j-1,k-1);
        else
            return false;
        
        
            
    }
};
---------------------------------------------------------
Optimised recursion : Using the fact that k is always=i+j
 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int i=s1.length();
        int j=s2.length();
        int k=s3.length();
        if(i+j!=k)
            return false;
        return solve(s1,s2,s3,i,j,i+j);
        
    }
    bool solve(string &s1,string &s2,string &s3,int i,int j,int k)
    {
        if(i<=0&&j<=0&&(i+j)<=0)
            return true;
        
        if(i>0&&j>0&&s1[i-1]==s2[j-1]&&s2[j-1]==s3[(i+j)-1])
            return solve(s1,s2,s3,i-1,j,(i+j)-1)||solve(s1,s2,s3,i,j-1,(i+j)-1);
        
        else if(i>0&&s1[i-1]==s3[(i+j)-1])
           return (solve(s1,s2,s3,i-1,j,(i+j)-1));
                   
        else if(j>0&&s2[j-1]==s3[(i+j)-1])
           return solve(s1,s2,s3,i,j-1,(i+j)-1);
        else
            return false;
        
        
            
    }
};
-----------------------------------------------------------------------
Memoization:

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int i=s1.length();
        int j=s2.length();
        int k=s3.length();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        if(i+j!=k)
            return false;
        return solve(s1,s2,s3,i,j,i+j,dp);
        
    }
    bool solve(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>>&dp)
    {
        if(i<=0&&j<=0&&(i+j)<=0)
            return true;
        
        if(i>0&&j>0&&dp[i][j]!=-1)
            return dp[i][j];
        if(i>0&&j>0&&s1[i-1]==s2[j-1]&&s2[j-1]==s3[(i+j)-1])
            return dp[i][j]=solve(s1,s2,s3,i-1,j,(i+j)-1,dp)||solve(s1,s2,s3,i,j-1,(i+j)-1,dp);
        
        else if(i>0&&s1[i-1]==s3[(i+j)-1])
           return (solve(s1,s2,s3,i-1,j,(i+j)-1,dp));
                   
        else if(j>0&&s2[j-1]==s3[(i+j)-1])
           return solve(s1,s2,s3,i,j-1,(i+j)-1,dp);
        else
            return false;
        
        
            
    }
};
------------------------------------------------------------------
DP:

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n=s1.length();
        int m=s2.length();
        int k=s3.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        if(n+m!=k)
            return false;
        
        
        dp[0][0]=true;
        for(int i=1;i<=s1.length();i++)
        {
            dp[i][0]=dp[i-1][0]&&s1[i-1]==s3[i-1];
        }
        for(int i=1;i<=s2.length();i++)
        {
            dp[0][i]=dp[0][i-1]&&s2[i-1]==s3[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i>0&&j>0&&s1[i-1]==s2[j-1]&&s2[j-1]==s3[(i+j)-1])
                dp[i][j]=dp[i-1][j]||dp[i][j-1];
                
                else if(i>0&&s1[i-1]==s3[(i+j)-1])
                dp[i][j]=dp[i-1][j];
                
                else if(j>0&&s2[j-1]==s3[(i+j)-1])
                 dp[i][j]=dp[i][j-1];
                
                else
                    dp[i][j]=false;
            }
        }
        return dp[n][m];
        
    }
    
};