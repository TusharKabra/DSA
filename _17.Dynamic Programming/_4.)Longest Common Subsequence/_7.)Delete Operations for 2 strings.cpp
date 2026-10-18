https://leetcode.com/problems/delete-operation-for-two-strings/


Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and 
another step to make "eat" to "ea".
-------------------------------------------------------------------------------
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n=word1.length();
        int m=word2.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return m+n-2*dp[n][m];
        
    }
};