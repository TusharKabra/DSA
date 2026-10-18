https://leetcode.com/problems/wildcard-matching/

?-Can be any one character
*-Can be any number of characters including 0 number of characters

EXAMPLE:
ab*
abdef


ab|abdef  OR  ab*|abde (star now has 1f)

Now ab*|abde results in ab|abde OR ab*|abd  (* has e and f)

ab*|abd = ab|abd OR ab*|ab

ab*|ab=ab|ab

a|a

"",""

Recursion tree(incomplete)

                  ab*  abdef
				  /        \
				            \
				 /           \
              ab|abdef  	ab*|abde	
                              /\
                             /  \
                       ab|abde   ab*|abd
                                  \
                                   \
								   ab*|ab
								   \
								    \
									
                                    								   
Thus recurrence: f(i-1,j)||f(i,j-1)	


-------------------------------------------------------------------------------------
RECURSION

class Solution {
public:
    
    bool solve(string &s,string &p,int i,int j)
    {
        if(i<0&&j<0)
            return true;
        
        if(i<0&&j>=0)    //Base case that if all the remaining char are stars
        {
            for(int k=0;k<=j;k++)
            {
                if(p[k]!='*')
                    return false;
            }
            return true;
        }
            
        if(i>=0&&j<0)   //Base case
        {
            return false;
        }

        
        if(s[i]==p[j]||p[j]=='?')
            return solve(s,p,i-1,j-1);
        
        if(p[j]=='*')
        return (solve(s,p,i-1,j)||solve(s,p,i,j-1));
        
        return false;    //If two diff letter comparison then false
        
    }
    bool isMatch(string s, string p) 
    {
        
        int n=s.length();
        int m=p.length();
        return solve(s,p,n-1,m-1);
        
        
    }
};

---------------------------------------------------------------------------------
Memoization

class Solution {
public:
    
    int solve(string &s,string &p,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0&&j<0)
            return true;
        
        if(i<0&&j>=0)    //Base case that if all the remaining char are stars
        {
            for(int k=0;k<=j;k++)
            {
                if(p[k]!='*')
                    return false;
            }
            return true;
        }
            
        if(i>=0&&j<0)   //Base case
        {
            return false;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];

        
        if(s[i]==p[j]||p[j]=='?')
            return dp[i][j]=solve(s,p,i-1,j-1,dp);
        
        if(p[j]=='*')
        return dp[i][j]=(solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp));
        
        return dp[i][j]=false;    //If two diff letter comparison then false
        
    }
    bool isMatch(string s, string p) 
    {
        
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int x= solve(s,p,n-1,m-1,dp);
        return x==1;
        
        
    }
};
------------------------------------------------------------------------

//1 indexed Memoization:

class Solution {
public:
    
    int solve(string &s,string &p,int i,int j,vector<vector<int>>&dp)
    {
        if(i==0&&j==0)
            return true;
        
        if(i==0&&j>0)    //Base case that if all the remaining char are stars
        {
            for(int k=1;k<=j;k++)   
            {
                if(p[k-1]!='*')
                    return false;
            }
            return true;
        }
            
        if(i>0&&j==0)   //Base case
        {
            return false;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];

        
        if(s[i-1]==p[j-1]||p[j-1]=='?')
            return dp[i][j]=solve(s,p,i-1,j-1,dp);
        
        if(p[j-1]=='*')
        return dp[i][j]=(solve(s,p,i-1,j,dp)||solve(s,p,i,j-1,dp));
        
        return dp[i][j]=false;    //If two diff letter comparison then false
        
    }
    bool isMatch(string s, string p) 
    {
        
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int x =solve(s,p,n,m,dp);
        return x==1;
        
        
    }
};
  