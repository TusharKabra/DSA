https://leetcode.com/problems/max-area-of-island/

You are given an m x n binary matrix grid. An island is a group of 1's 
(representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.


class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m,int i,int j,int &c)
    {
        if(i<0||i>=n||j<0||j>=m)
            return ;
        if(grid[i][j]!=1||vis[i][j]==1)
            return;
        c++;
        vis[i][j]=1;
        dfs(grid,vis,n,m,i+1,j,c);
        dfs(grid,vis,n,m,i,j+1,c);
        dfs(grid,vis,n,m,i-1,j,c);
        dfs(grid,vis,n,m,i,j-1,c);
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cmax=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]==1)
                {
                    int c=0;
                    dfs(grid,vis,n,m,i,j,c);
                    cmax=max(c,cmax);
                }
            }
        }
        return cmax;
        
    }
};