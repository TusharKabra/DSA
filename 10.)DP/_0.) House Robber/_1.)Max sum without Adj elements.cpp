https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers

is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.

=================================================================
MEMOIZATION

int solve(vector<vector<int> > &A,int i,int sum,vector<int>&dp)
{
    if(i<0)
    return 0;
    
    if(dp[i]!=-1)
    return dp[i];
    int mx=max(A[0][i],A[1][i]);
    
    int pick=mx+solve(A,i-2,sum+mx,dp);
    int not_pick=solve(A,i-1,sum,dp);
    
    return dp[i]=max(pick,not_pick);
}


int Solution::adjacent(vector<vector<int> > &A) 
{
    int n=A[0].size();
    vector<int>dp(n,-1);
    return solve(A,n-1,0,dp);
}

========================================================================

DP

dp[i] is the max till and including the index i.

int solve(vector<vector<int> > &A,int i,int sum,vector<int>&dp)
{
    int n=A[0].size();
    for(int i=2;i<n;i++)
    {
        int mx=max(A[0][i],A[1][i]);
        int pick=mx+dp[i-2];
        int not_pick=dp[i-1];
        
        dp[i]=max(pick,not_pick);
    }
    
    return dp[n-1];
    
}


int Solution::adjacent(vector<vector<int> > &A) 
{
    int n=A[0].size();
    vector<int>dp(n,0);
    dp[0]=max(A[0][0],A[1][0]);
    if(n>1)
    {
        dp[1]=max({A[0][1],A[1][1],dp[0]});
    }
    
    return solve(A,n-1,0,dp);
}

