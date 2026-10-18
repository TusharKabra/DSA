https://leetcode.com/problems/01-matrix/



//Check the Solution Tab


BFS SOLUTION:
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((mat[i][j]==0))
                {
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int j=0;j<4;j++)
            {
                int newx=x+dx[j];
                int newy=y+dy[j];
                if(newx<0||newy<0||newx==n||newy==m||mat[newx][newy]==0)
                    continue;
                
                if(dist[x][y]+1<dist[newx][newy])
                {
                    dist[newx][newy]=dist[x][y]+1;
                    q.push({newx,newy});
                }
            }
            
        }
        return dist;
    }
};



Time complexity: O(rc)

Since, the new cells are added to the queue only if their current distance is 
greater than the calculated distance, cells are not likely to be added multiple times.

Space complexity: O(rc)

An additional O(rc) space is required to maintain the queue.
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
DP Solution O(1) space:

Intuition

The distance of a cell from 0 can be calculated if we know the nearest 
distance for all the neighbors, in which case the distance is the minimum 
distance of any neighbor + 1. And, instantly, the words that come to mind 
are Dynamic Programming (DP)!!
From each 1, the minimum path to 0 could be in any direction. So, we need 
to check all the 4 directions. In one iteration from top to bottom, we can 
check left and top directions, and we need another iteration from bottom 
to top to check for right and bottom directions.
--------------------------------------------------------------------------------
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
		
        // starting from 0, 0. Checking current pos with top and left
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(mat[row][col] == 0) {
                    dp[row][col] = 0;
                    continue;
                }
                
                if(row > 0 && dp[row - 1][col] != INT_MAX) {
                    dp[row][col] = min(dp[row][col], dp[row - 1][col] + 1);
                }
                
                if(col > 0 && dp[row][col - 1] != INT_MAX) {
                    dp[row][col] = min(dp[row][col], dp[row][col - 1] + 1);
                }
            }
        }
        
		// starting from n - 1, m - 1. Checking current pos with bottom and right
        for(int row = n - 1; row >= 0; row--) {
            for(int col = m - 1; col >= 0; col--) {
                if(mat[row][col] == 0) {
                    dp[row][col] = 0;
                    continue;
                }
                
                if(row < n - 1 && dp[row + 1][col] != INT_MAX) {
                    dp[row][col] = min(dp[row][col], dp[row + 1][col] + 1);
                }
                
                if(col < m - 1 && dp[row][col + 1] != INT_MAX) {
                    dp[row][col] = min(dp[row][col], dp[row][col + 1] + 1);
                }
            }
        }
        return dp;
    }
};
