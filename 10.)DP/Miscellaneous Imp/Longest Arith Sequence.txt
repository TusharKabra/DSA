https://leetcode.com/problems/longest-arithmetic-subsequence/

APPROACH-1(Ideally this should work but is giving TLE)


class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        int result = 0;
        vector<unordered_map<int, int>> dp(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i]-A[j];
                dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
                result = max(result, dp[i][diff]);
            }
        }
        return result;
    }
};

-------------------------------------------------------------------------------------------

Approach-2 (DOES NOT GIVE TLE)
dp[i][diff] gives us the length of the arthematic sequence ends at index i with difference diff
So for each dp[j][diff] which has a difference diff with previous index i 
will be maximum(2,dp[i][diff])--> 2 means the sequence has just begun at these two indices 
where if previous i has already sme length then the length is increased by 1.
Result will be maximum of all dp[j][diff].

we use the maximum length of 1001 here because as per the given constraints 
the difference can have a minimum value of -500 and maximum value of 500 so 
the difference will be increased by 500 to keep the index positive in the matrix.

class Solution 
{
public:
    int longestArithSeqLength(vector<int>& nums) {
    int n=nums.size(), res=0;
    
    vector<vector<int>> dp(n, vector<int>(1001,0));
    
    for (int i=0; i<n; i++) 
	{
        for (int j=0; j<i; j++) 
		{
            int diff = nums[i] - nums[j] +500;
            dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
            res = max(res, dp[i][diff]);
        }
    }

}
}

For: [1,2,3,4,5]

0 0 0 0 0 0 0 0 0 0 
0 2 0 0 0 0 0 0 0 0 
0 3 2 0 0 0 0 0 0 0 
0 4 2 2 0 0 0 0 0 0 
0 5 3 2 2 0 0 0 0 0 