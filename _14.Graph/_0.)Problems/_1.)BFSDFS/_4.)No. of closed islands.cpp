https://leetcode.com/problems/number-of-closed-islands/

Given a 2D grid consists of 0s (land) and 1s (water).  An island is a 
maximal 4-directionally connected group of 0s and a closed island is an 
island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
--------------------------------------------------------------------------------

Approach:
All the islands which touch the border are not closed so sink them(convert 0 to 1 for that component)
Now again traverse over the grid and if you encounter a zero then that is an island and again 
convert the entire connected componet to 1's

===========================================================================================
DFS Approach:
class Solution {
public:
    int m,n;
   
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0||i>=n||j<0||j>=m||grid[i][j])
            return;
        
        grid[i][j]=1;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }

    int closedIsland(vector<vector<int>>& grid) 
    {
        n=grid.size();
        m=grid[0].size();
        
        //first convert all the zeroes connected to any boundary to 1 
        //as they are not island
        
        for(int i=0;i<m;i++)
        {
                dfs(grid,0,i);
                dfs(grid,n-1,i);
        }
        for(int i=0;i<n;i++)
        {
                dfs(grid,i,0);
                dfs(grid,i,m-1);
        }
        
        
        //Now if we encounter any zero then it is part of an island
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    c++;
                    dfs(grid,i,j);
                }    
            }
        }
        return c;
    }
};

---------------------------------------------------------------------------------------------------------

BFS Approach:
int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        /*1. sink the islands which touch border (they  are the islands which are not closed) */
        for(int i = 0; i < m; ++i)  if(grid[i][0] == 0) sinkIsland(grid, i, 0); //left border
        for(int j = 0; j < n; ++j)  if(grid[0][j] == 0) sinkIsland(grid, 0, j); //top border
        for(int i = 0; i < m; ++i)  if(grid[i][n-1] == 0) sinkIsland(grid, i, n-1); //right border
        for(int j = 0; j < n; ++j)  if(grid[m-1][j] == 0) sinkIsland(grid, m-1, j); //bottom border
        
        /*2. now the remaining islands will be closed ones */
        int cnt_closed = 0;
        for(int i = 1; i < m-1; ++i)
            for(int j = 1; j < n-1; ++j) {
                if(grid[i][j] == 0) {
                    ++cnt_closed;
					/*we will count the island then sink (to mark it as visited)*/
                    sinkIsland(grid, i, j);
                }
            }
        return cnt_closed;
    }
    
    /* This BFSfunction will sink(to mark it as visited) the island by placing 1 instead of 0 */
    void sinkIsland(vector<vector<int>>& grid, int i, int j) {
        int dir[]{0, -1, 0, 1, 0};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;

        grid[i][j] = 1;
        q.push({i,j});
        while(!q.empty()) {
            pair<int,int> curr_pos = q.front();
            q.pop();
            
            /* finding land from all  4 directions of curr pos and sink*/
            for(int d = 0; d < 4; ++d) {
                i = curr_pos.first + dir[d];
                j = curr_pos.second + dir[d+1];
                if(i < 0 || j < 0 || i == m || j == n) continue;
                
                if(grid[i][j] == 0) {
                    grid[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
    }