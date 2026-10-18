https://leetcode.com/problems/minimum-falling-path-sum/

----------------------------------------------------------------------------

Memoization:


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int mi=1e9;
        int n=matrix.size();
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int j=0;j<matrix[0].size();j++)
        {
            mi=min(mi,solve(matrix,n-1,j,dp));
        }
        return mi;
        
    }
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp)
    {
        if(j<0||j>=matrix[0].size())
            return 1e9;
        
        if(i<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int x=solve(matrix,i-1,j,dp);
        int y=solve(matrix,i-1,j+1,dp);
        int z=solve(matrix,i-1,j-1,dp);
        
        return dp[i][j]=matrix[i][j]+min(x,min(y,z));
        
        
            
    }
};
----------------------------------------------------
Alterbate Bottom-UP-Memoization:

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int mi=1e9;
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        for(int j=0;j<matrix[0].size();j++)
        {
            mi=min(mi,solve(matrix,0,j,dp));
        }
        return mi;
        
    }
    int solve(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp)
    {
        if(j<0||j>=matrix[0].size())
            return 1e9;  //can return -1e9 if max falling path sum.
        
        if(i==matrix.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int x=solve(matrix,i+1,j,dp);
        int y=solve(matrix,i+1,j+1,dp);
        int z=solve(matrix,i+1,j-1,dp);
        
        return dp[i][j]=matrix[i][j]+min(x,min(y,z));

    }
};
--------------------------------------------------------------------------

DP

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        
    
        int n = matrix.size();
        int m = matrix[0].size();
    
        vector<vector<int>> dp(n,vector<int>(m,0));
    
        // Initializing first row - base condition
        for(int j=0; j<m; j++){
            dp[0][j] = matrix[0][j];
        }
    
        for(int i=1; i<n; i++)
        {
            for(int j=0;j<m;j++)
            {
            
            int up = matrix[i][j] + dp[i-1][j];
            
            int leftDiagonal= matrix[i][j];
            if(j-1>=0) leftDiagonal += dp[i-1][j-1];
            else leftDiagonal += 1e9;
            
            int rightDiagonal = matrix[i][j];
            if(j+1<m) rightDiagonal += dp[i-1][j+1];
            else rightDiagonal += 1e9;
            
            dp[i][j] = min(up, min(leftDiagonal,rightDiagonal));
            
           }
        }
        
        int mi = INT_MAX;

        for(int j=0; j<m;j++)
		{
            mi = min(mi,dp[n-1][j]);
        }

        return mi;
	}	
};