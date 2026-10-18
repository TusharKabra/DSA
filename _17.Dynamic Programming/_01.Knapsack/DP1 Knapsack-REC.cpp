RECURSIVE SOLN:

int knapSack(int W, int wt[], int val[], int n)
{
 
    // Base Case:if no item then no profit so return 0. similarly if capacity is zero then also return 0
    if (n == 0 || W == 0)
        return 0;
 
    // If weight of the nth item is more
    // than Knapsack capacity W, then
    // this item cannot be included
    // in the optimal solution

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
 
    // Return the maximum of two cases:
    // (1) nth item included
    // (2) not included
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
                             knapSack(W, wt, val, n - 1));
}
-------------------------------------------------------------------------------------------------------------------------
2.) MEMOIZATION:
We create table using variables which are changing in recursion. Here n and w were changing.
Instead of n, i is used in the following code

INITIALISE dp[n+1][w+1] with -1
return knapSackRec(W, wt, val, n - 1, dp);



int knapSackRec(int W, int wt[],int val[], int i,int** dp)
{
    // base condition
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];
 
    if (wt[i] > W) {
 
        // Store the value of function call
        // stack in table before return
        dp[i][W] = knapSackRec(W, wt,val, i - 1,dp);

        return dp[i][W];
    }
    else {
        // Store value in a table before return
        dp[i][W] = max(val[i] + knapSackRec(W - wt[i],wt, val,i - 1, dp),knapSackRec(W, wt, val,i - 1, dp));

 
        // Return value of table after storing
        return dp[i][W];
    }
}

---------------------------------------------------------------------------------------------------------------------
3. Bottom-Up

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <n+1; i++)
    {
        for(w = 0; w < W+1; w++)
        {
            if (i == 0 || w == 0)   //1st row and 1st column initialise to zero using base condition
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
------------------------------------------------------------------------------------

Optimised Soln:



int KnapSack(int val[], int wt[], int n, int W)
{
    // array to store final result
    //dp[i] stores the profit with KnapSack capacity "i"
    int dp[W+1];
     
    //initially profit with 0 to W KnapSack capacity is 0
    memset(dp, 0, sizeof(dp));
 
    // iterate through all items
    for(int i=0; i < n; i++)
        //traverse dp array from right to left
        for(int j=W; j>=wt[i]; j--)
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
			
    /*above line finds out maximum of  dp[j](excluding ith element value)
      and val[i] + dp[j-wt[i]] (including ith element value and the
      profit with "KnapSack capacity - ith element weight") */   
	  
    return dp[W];
}
 