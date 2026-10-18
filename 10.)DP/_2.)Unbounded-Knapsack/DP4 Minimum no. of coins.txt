https://leetcode.com/problems/coin- change/

Arr[]=1,2,3
Sum=5

2+3=5 and the answer is 2 as this is the lowest no. of coins needed to make the sum 5

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        int m=amount;
        vector<vector<long long int>>dp(n+1,vector<long long int>(m+1,INT_MAX-1));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        // for(int i=1;i<=amount;i++)
        // {
        //     dp[0][i]=0;
        // }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
        }
        if(dp[n][amount]==INT_MAX-1)
            return -1;
        else
            return dp[n][amount];
        
    }
};