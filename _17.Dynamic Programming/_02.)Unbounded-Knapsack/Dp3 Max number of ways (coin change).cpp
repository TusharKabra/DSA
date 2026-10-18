https://leetcode.com/problems/coin-change-ii/

RECURSIVE

// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n

int count(int S[], int m, int n)
{
     
    // If n is 0 then there is 1 solution
    // (do not include any coin)
    if (n == 0)
        return 1;
     
    // If n is less than 0 then no
    // solution exists
    if (n < 0)
        return 0;
 
    // If there are no coins and n
    // is greater than 0, then no
    // solution exist
    if (m <= 0 && n >= 1)
        return 0;
 
    // count is sum of solutions (i)
    // including S[m-1] (ii) excluding S[m-1]
    return count(S, m - 1, n) +
           count(S, m, n - S[m - 1]);
}

----------------------------------------------------
MEMOIZATION:
int coinchange(vector<int>& a, int v, int n,
               vector<vector<int> >& dp)
{
    if (v == 0)
        return dp[n][v] = 1;
    if (n == 0)
        return 0;
    if (dp[n][v] != -1)
        return dp[n][v];
    if (a[n - 1] <= v) {
        // Either Pick this coin or not
        return dp[n][v] = coinchange(a, v - a[n - 1], n, dp)
                          + coinchange(a, v, n - 1, dp);
    }
    else // We have no option but to leave this coin
        return dp[n][v] = coinchange(a, v, n - 1, dp);
}
int32_t main()
{
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        int n, v;
        n = 3, v = 4;
        vector<int> a = { 1, 2, 3 };
        vector<vector<int> > dp(n + 1,
                                vector<int>(v + 1, -1));
        int res = coinchange(a, v, n, dp);
        cout << res << endl;
    }
}

--------------------------------------------------------------------
DP

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//sort(arr, arr + n, greater<int>()); 
//cout<<fixed<<setprecision(20)<<(double)(result)<<endl;
 
ll subset(vector<ll>&arr,ll n,ll m,vector<vector<ll>>&dp)
{
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[i][0]=1;
    }
    
    dp[0][0]=1;
	
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arr[i-1]<=j)
            { 
			    //(dont take) or (take and again stay at that index as unlimited coin supply)
                dp[i][j]=dp[i-1][j]+dp[i][j-arr[i-1]];   
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[m][n];
}


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    vector<ll>arr(m,0);
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    vector<vector<ll>>dp(m+1,vector<ll>(n+1,0ll));
    ll c=subset(arr,n,m,dp);
    cout<<c<<endl;
}

--------------------------------------------------------------------------
OPTIMIZED:
int count( int S[], int m, int n )         
{         
 // table[i] will be storing the number of solutions for         
 // value i. We need n+1 rows as the table is constructed         
 // in bottom up manner using the base case (n = 0)         
 int table[n+1];  
       
 // Initialize all table values as 0         
 memset(table, 0, sizeof(table));     
    
 // Base case (If given value is 0)         
 table[0] = 1;         

 // Pick all coins one by one and update the table[] values         
 // after the index greater than or equal to the value of the         
 // picked coin         
 for(int i=0; i<m; i++)         
 for(int j=S[i]; j<=n; j++)         
 table[j] += table[j-S[i]];         
 return table[n];         
}         