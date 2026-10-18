https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e7));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        
        if(q.size()==n*m||q.size()==0)
            return -1;
        
        int ans=0;
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            for(int i=0;i<4;i++)
            {
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx<0||newx>=n||newy<0||newy>=m)
                    continue;
                
                if(dist[x][y]+1<dist[newx][newy])
                {
                    dist[newx][newy]=dist[x][y]+1;
                    ans=max(ans,dist[newx][newy]);
                    q.push({newx,newy});
                }
                
            }
            
        }
        return ans;
    }
};


=================================================================

DP SOLN-
class Solution {
    public int maxDistance(int[][] grid) {
        int n = grid.length, m = grid[0].length, res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) continue;
                grid[i][j] = 201; //201 here cuz as the despription, the size won't exceed 100.
                if (i > 0) grid[i][j] = Math.min(grid[i][j], grid[i-1][j] + 1);
                if (j > 0) grid[i][j] = Math.min(grid[i][j], grid[i][j-1] + 1);
            }
        }
        
        for (int i = n-1; i > -1; i--) {
            for (int j = m-1; j > -1; j--) {
                if (grid[i][j] == 1) continue;
                if (i < n-1) grid[i][j] = Math.min(grid[i][j], grid[i+1][j] + 1);
                if (j < m-1) grid[i][j] = Math.min(grid[i][j], grid[i][j+1] + 1);
                res = Math.max(res, grid[i][j]); //update the maximum
            }
        }
        
        return res == 201 ? -1 : res - 1;
    }
}