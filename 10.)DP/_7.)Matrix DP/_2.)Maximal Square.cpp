Prereq:Count no. of square submatrices

https://leetcode.com/problems/maximal-square/
------------------------------------------------------------
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int mx=0;
        for(int i=0;i<n;i++)
        {
            dp[i][0]=matrix[i][0]-'0';
            mx=max(mx,dp[i][0]);
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i]-'0';
            mx=max(mx,dp[0][i]);
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]=='0')
                    dp[i][j]=0;
                else
                dp[i][j]=1+min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                
                mx=max(mx,dp[i][j]);
            }
            
            
        }
        return (mx*mx);
        
    }
};

--------------------------------------------------------------------
Space Optimal Solution

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix[0].size(); 
        int n = matrix.size();
        int mx = 0;
        
        vector<int> pre(m, 0), cur(m, 0);
        
        for(int i=0;i<m;i++)
        {
            pre[i]=matrix[0][i]-'0';
            mx= max(mx,pre[i]);
        }

//we are starting from the first row so we initialise the 
//prev row with the content of the first row of matrix and the current row as 0.     
        for(int i = 1; i<n;i++) 
        {
            for(int j=0;j<m;j++) 
            {
                
                
                if (matrix[i][j] == '0') 
                {
                    cur[j]=0;
                    continue;
                } 
                if(j==0)                    //earlier we had directly filled the 1st column,now it is an edge case      
                {
                    cur[j]=matrix[i][j]-'0';
                }
                else 
                {
                    cur[j]=min(pre[j-1], min(pre[j],cur[j-1]))+1;
                }
                mx=max(cur[j],mx);
                
            }
            
            for(int i=0;i<m;i++)
                pre[i]=0;
            
            swap(pre, cur);
        }
        
        return (mx*mx);
    }
};