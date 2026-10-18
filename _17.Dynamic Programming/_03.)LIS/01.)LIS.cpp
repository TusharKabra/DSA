https://leetcode.com/problems/longest-increasing-subsequence/ 

Memoization

int f(int idx, int prev_idx, int n, int a[],
      vector<vector<int> >& dp)
{
    if (idx == n) {
        return 0;
    }
 
    if (dp[idx][prev_idx + 1] != -1) {
        return dp[idx][prev_idx + 1];
    }
 
    int notTake = 0 + f(idx + 1, prev_idx, n, a, dp);
    int take = INT_MIN;
    if (prev_idx == -1 || a[idx] > a[prev_idx]) {
        take = 1 + f(idx + 1, idx, n, a, dp);
    }
 
    return dp[idx][prev_idx + 1] = max(take, notTake);
}

// Function to find length of longest increasing
// subsequence.
int longestSubsequence(int n, int a[])
{
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
    return f(0, -1, n, a, dp);
}

----------------------------------------------------------------------------------------

O(n^2) approach:

/* lis() returns the length of the longest
  increasing subsequence in arr[] of size n */

int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>lis(n,1); //Initialising with 1 as each element is an increasing sequence of length 1
        //lis[0]=1;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i]&&lis[i]<lis[j]+1)
                    lis[i]=lis[j]+1;
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,lis[i]);
        }
        return mx;
    }