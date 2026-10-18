1.)RECURSION

// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
  
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;

    // If last element is greater than sum,
    // then ignore it
    if (set[n - 1] > sum)
        return isSubsetSum(set, n - 1, sum);

    /* else, check if sum can be obtained by any 
of the following:
      (a) including the last element
      (b) excluding the last element   */
    return isSubsetSum(set, n - 1, sum)
           || isSubsetSum(set, n - 1, sum - set[n - 1]);
}
-----------------------------------------------------------------
MEMOIZATION

In this method, we also follow the recursive approach but In this method,
we use another 2-D matrix in  we first initialize with -1 or any negative value.


// Check if possible subset with 
// given sum is possible or not
int subsetSum(int a[], int n, int sum)
{
    
    // If the sum is zero it means 
    // we got our expected sum
    if (sum == 0)
        return 1;
        
    if (n <= 0)
        return 0;
  
    // If the value is not -1 it means it 
    // already call the function 
    // with the same value.
    // it will save our from the repetition.
    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];
  
    // if the value of a[n-1] is
    // greater than the sum.
    // we call for the next value
    if (a[n - 1] > sum)
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum);
    else
    {
        
        // Here we do two calls because we 
        // don't know which value is 
        // full-fill our criteria
        // that's why we doing two calls
        return tab[n - 1][sum] = subsetSum(a, n - 1, sum) || 
                       subsetSum(a, n - 1, sum - a[n - 1]);
    }
}

---------------------------------------------------------------------

3. BOTTOM UP DP:

// Returns true if there is a subset of set[]
// with sum equal to given sum

bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];

    // If sum is 0, then answer is true   //BASE CONDITION
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty,  //BASE CONDITION
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in bottom up manner

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];
}
---------------------------------------------------------------------
OPTIMISD AND SUPER OPTIMISED PROBLEM

bool isSubsetSum(int arr[], int n, int sum)
{
   
    // The value of subset[i%2][j] will be true
    // if there exists a subset of sum j in
    // arr[0, 1, ...., i-1]
    bool subset[2][sum + 1];
 
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
 
            // A subset with sum 0 is always possible
            if (j == 0)
                subset[i % 2][j] = true;
 
            // If there exists no element no sum
            // is possible
            else if (i == 0)
                subset[i % 2][j] = false;

            else if (arr[i - 1] <= j) 
                subset[i % 2][j] = subset[(i + 1) % 2]
             [j - arr[i - 1]] || subset[(i + 1) % 2][j];
            else
                subset[i % 2][j] = subset[(i + 1) % 2][j];
        }
    }
 
    return subset[n % 2][sum];
}

---------------------------------------------------------------------

Super Optimised

To further reduce space complexity, we create a boolean 1D array subset[sum+1]. 
Using bottom up manner we can fill up this table. 
The idea is that we can check
if the sum till position “i” is possible then if the current element in the array
at position j is x, then sum i+x is also possible. We traverse the sum
array from back to front so that we don’t count any element twice. 

bool isPossible(int elements[], int sum, int n)
{
    int dp[sum + 1];
     
    // Initializing with 1 as sum 0 is
    // always possible
    dp[0] = 1;
     
    // Loop to go through every element of
    // the elements array
    for(int i = 0; i < n; i++)
    {
         
        // To change the values of all possible sum
        // values to 1
        for(int j = sum; j >= elements[i]; j--)
        {
            if (dp[j - elements[i]] == 1)
                dp[j] = 1;
        }
    }
     
    // If sum is possible then return 1
    if (dp[sum] == 1)
        return true;
         
    return false;
}




