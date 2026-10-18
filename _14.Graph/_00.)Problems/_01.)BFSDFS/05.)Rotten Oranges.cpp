https://leetcode.com/problems/rotting-oranges/


You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.

--------------------------------------------------------------------------------------------
ALGO:
1.)Put all rotten oranges in the queue
2.)Then do the bfs and in each iteration rot the adjacentclean oranges as well and put them in the queue
3.)The queue will always have only those many oranges which have been rotten at a particular second 
and the oranges corresponding to previous second will be popped out.So if the queue is not empty 
it means that day needs to be inc.
----------------------------------------------------------------------------------------------------------
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        int countFresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    countFresh++;
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                }
            }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        int time=0;
        while(!q.empty())
        {
            int x=q.front().first.first;
            int y=q.front().first.second;
            time=q.front().second;
            vis[x][y]=1;
            q.pop();
            
            int dx[]={1,0,-1,0};
            int dy[]={0,1,0,-1};
            
            for(int i=0;i<4;i++)
            {
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0&&newy>=0&&newx<n&&newy<m&&!vis[newx][newy]&&grid[newx][newy]==1)
                {
                    countFresh--;
                    grid[newx][newy]=2;
                    q.push({{newx,newy},time+1});
                }
            }
        }
        
        if(countFresh>0)
            return -1;
        return time;
        
        
    }
};