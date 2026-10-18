https://leetcode.com/problems/number-of-islands/

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
--------------------------------------------------------------------
class Solution {
public:
    
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m,vector<vector<int>>& vis)
    {
        if(i<0||i>=n||j<0||j>=m)
            return ;
        if(vis[i][j]||grid[i][j]=='0')
            return;
        
        vis[i][j]=1;
        dfs(grid,i+1,j,n,m,vis);
        dfs(grid,i,j+1,n,m,vis);
        dfs(grid,i-1,j,n,m,vis);
        dfs(grid,i,j-1,n,m,vis);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    c++;
                    dfs(grid,i,j,n,m,vis);
                }
            }
        }
        
        return c;
        
    }
    
};