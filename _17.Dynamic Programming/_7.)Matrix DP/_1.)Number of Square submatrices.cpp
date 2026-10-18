https://leetcode.com/problems/count-square-submatrices-with-all-ones/ 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
-----------------------------------------------------------------------------
Let dp[i][j]-How many squares end at i,j that is the right bottom is (i,j)
Also the 1st row and 1st col will be same as the matrix


Resulting dp array will look something like this-
0 1 1 1
1 1 2 2 
0 1 2 3
------------------------------------------------------------------------------

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=matrix[i][0];
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                    dp[i][j]=0;
                else
                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                sum+=dp[i][j];
            }
        }
        return sum;

    }
};

