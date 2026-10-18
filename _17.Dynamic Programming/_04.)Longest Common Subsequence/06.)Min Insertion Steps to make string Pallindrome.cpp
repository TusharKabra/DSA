https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/


Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
--------------------------------------------------------------
HINT: We can find the length of the largest pallindromic subsequence.(Done earlier)
Thus just subtract this from the length of the given string and we get the answer.


class Solution {
public:
    int minInsertions(string s) 
    {
        string x=s;
        reverse(x.begin(),x.end());
        
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==x[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
		//dp[n][n] has the value of Largest Pallindromic subseq.
        return n-dp[n][n];
        
    }
};