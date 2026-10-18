Given an array arr[] of length N and an integer X, the task 
is to find the number of subsets with a sum equal to X

Tabulation Method:


Idea:
if (A[i] > j)
DP[i][j] = DP[i-1][j]
else 
DP[i][j] = DP[i-1][j] + DP[i-1][j-A[i]]

This means that if the current element has a value greater than the 
‘current sum value’ we will copy the answer for previous cases
And if the current sum value is greater than the ‘ith’ element we will 
see if any of the previous states have already experienced the
sum=’j’ and any previous states experienced a value ‘j – A[i]’ which 
will solve our purpose


int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int tab[n + 1][sum + 1];
  // Initializing the first value of matrix
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++) //Base condition
        tab[0][i] = 0;
    for (int i = 1; i <= n; i++)   //Base condition
        tab[i][0] = 1;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    }
 
 
    return tab[n][sum];
}
 