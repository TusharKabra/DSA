https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

For each cell we try to find out what is the largest increasing path 
we can make from that cell if it is the starting of the sequence.
We store the results of each of the subproblems in the dp matrix.


Matrix

9 9 4
6 6 8
2 1 1

Then dp will be-

1 1 2
2 2 1
3 4 1

=====================================================================================
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dp[i][j])
                {
                    mx=max(mx,dp[i][j]);
                    continue;
                }
                else
                {
                    dp[i][j]=solve(i,j,matrix,dp);
                    mx=max(mx,dp[i][j]);
                }
            }
        }
        return mx;
    }
    
    int solve(int x,int y,vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        // if(x<0||x>=matrix.size()||y<0||y>=matrix[0].size())
        // {
        //     return 0;
        // }
        
        if(dp[x][y]>0)
            return dp[x][y];
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1};
        int len=0;
        for(int i=0;i<4;i++)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx<0||newx>=matrix.size()||newy<0||newy>=matrix[0].size())
                continue;
            if(matrix[x][y]>=matrix[newx][newy])
                continue;
        
            dp[x][y]=1+solve(newx,newy,matrix,dp);
            len=max(len,dp[x][y]);
        }
        dp[x][y]=max(1,len);
        return dp[x][y];
                          
    }
};