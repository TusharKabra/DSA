https://leetcode.com/problems/longest-common-subsequence/ 
 
 LONGEST COMMON SUBSEQUENCE

LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.


Recursive

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

main()
{
lcs(X,Y,m,n);
}

--------------------------------------------------------------------
Memoization

int lcs(char* X, char* Y, int m, int n,
        vector<vector<int> >& dp)
{

    if (m == 0 || n == 0)
        return 0;
		
	if (dp[m][n] != -1) 
	{
        return dp[m][n];
    }
	
    if (X[m - 1] == Y[n - 1])
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
 
    
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
                          lcs(X, Y, m - 1, n, dp));
						  
}

-------------------------------------------------------------------------
DP

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.size();
        int m=text2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        for(int j=0;j<=n;j++)
        {
            dp[j][0]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];   
    }
};

--------------------------------------------------------------------------
Space Optimised

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.size();
        int m=text2.size();
        
        vector<int>prev(m+1,0); //For the first row we initialise 
                                //as 0 due to base case
        
        vector<int>curr(m+1,0); //Simple initialisation
        
        
        
        // for(int i=0;i<=m;i++)
        // {
        //     prev[i]=0;   //Again a base case condition not needed here but thats
        //                  //the way to do this
        // }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    curr[j]=1+prev[j-1];
                }
                else
                {
                    curr[j]=max(prev[j],curr[j-1]);
                }
            }
            prev=curr;
        }
        
        return prev[m];   
    }
};
