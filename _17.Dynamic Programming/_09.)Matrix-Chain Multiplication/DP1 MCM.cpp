
//Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The problem is not actually to perform the multiplications, but merely to decide in which 
order to perform the multiplications.

//Basic Maths

For two matrix 5*30 and 30*10: the multiplication would require 5*30*10 operations. 
Thus minimise this no.

//For 1st Matrix dimensions are: A[0]*A[1]
//For 2nd Matrix dimensions are: A[1]*A[2]
for ith matrix: A[i-1]*A[i]

Rule
//i is the start point and j the end point
//Try all partitions so run a loop to try all partitions.
//return the best possible 2 partitions


Definition:
Start point: f(1,n-1)
f(i,k)+f(k+1,j)
f(1,4)=Min. no. of multip required to multiply matrix 1 to 4

------------------------------------------------------------------------------
//Recursive Approach

//initial value of i is 1 and j is n-1
int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;
 
    // place parenthesis at different places
    // between first and last matrix, recursively
    // calculate count of multiplications for
    // each parenthesis placement and return the
    // minimum count
	
    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];
 
        if (count < min)
            min = count;
    }
 
 
    // Return minimum count
    return min;
}
 
 
 
//MEMOIZATION

// Function for matrix chain multiplication
int matrixChainMemoised(int* p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k)
                     + matrixChainMemoised(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}
 
 