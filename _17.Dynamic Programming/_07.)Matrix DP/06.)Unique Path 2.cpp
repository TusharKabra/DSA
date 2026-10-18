https://leetcode.com/problems/unique-paths-ii/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long long int>>dp(m+1,vector<long long int>(n+1,0));
		
		//Cant reach any block after the obstacle in the 1st row or column
        for(int i=0;i<m;i++)
        {
            
            if(obstacleGrid[i][0]==1)
            {
                dp[i][0]=0;
                break;
            }
            else
                dp[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            
            if(obstacleGrid[0][i]==1)   
            {
                dp[0][i]=0;
                break;
            }
            else
                dp[0][i]=1;
        }
        
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
    
    
};
 