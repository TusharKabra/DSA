https://leetcode.com/problems/max-dot-product-of-two-subsequences/


F(X, Y) = max (
F(X-1, Y), // ignore the last number from first
F(X, Y-1), // ignore the last number from second
F(X-1, Y-1) + nums[X] * nums[Y], // use last numbers from both the first and the second
nums[X] * nums[Y], // only use last numbers from both the first and the second
F(X-1, Y-1), // ignore both the last numbers
)

NOTE-
Actually the last case of ignoring both the no.s is redundant.
If F(X-1, Y-1) is indeed the actual answer, it will propagate via F(X-1, Y) or F(X, Y-1).

Why?
F(X-1, Y) = max(F(X-1, Y-1) ,
F(X-2, Y),
F(X-2, Y-1) + nums1[X-1]*nums[Y])
Similarly for F(X, Y-1) = ....


SEE THIS FOR MORE EXPLAN-
https://leetcode.com/problems/max-dot-product-of-two-subsequences/discuss/648528/Common-DP-pattern-with-diagram-explanation-QandA
============================================================================
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1e8));
        return solve(nums1,nums2,n-1,m-1,dp);
        
    }
    
    int solve(vector<int>& nums1, vector<int>& nums2,int n,int m,vector<vector<int>>&dp)
    {
        if(n<0||m<0)
            return -1e8;  //cant take empty sequence
        if(dp[n][m]!=-1e8)
            return dp[n][m];
        
        int x=nums1[n]*nums2[m]+solve(nums1,nums2,n-1,m-1,dp); 
        int y=solve(nums1,nums2,n-1,m,dp);
        int z=solve(nums1,nums2,n,m-1,dp);
        int p=nums1[n]*nums2[m];
        int q=solve(nums1,nums2,n-1,m-1,dp);
        
        return dp[n][m]=max({p,q,x,y,z});
    }
};

============================================================================
class Solution 
{
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1e8));
        return solve(nums1,nums2,n-1,m-1,dp);
        
    }
    
    int solve(vector<int>& nums1, vector<int>& nums2,int n,int m,vector<vector<int>>&dp)
    {
        if(n<0||m<0)
            return -1e8;
        if(dp[n][m]!=-1e8)
            return dp[n][m];
        
        int x=nums1[n]*nums2[m]+solve(nums1,nums2,n-1,m-1,dp);
        int y=solve(nums1,nums2,n-1,m,dp);
        int z=solve(nums1,nums2,n,m-1,dp);
        int q=nums1[n]*nums2[m];
        
        return dp[n][m]=max(q,max(x,max(y,z)));
    }
};

------------------------------------------------------------------------------------
DP:

class Solution {
public:
        const int INF = 1e7;
        int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -INF));
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                dp[i][j] = max({
                                nums1[i-1]*nums2[j-1],
                                dp[i-1][j-1] + nums1[i-1]*nums2[j-1],
                                dp[i-1][j],
                                dp[i][j-1]
                               });
            }
        }
        return dp[n][m];
    }
};