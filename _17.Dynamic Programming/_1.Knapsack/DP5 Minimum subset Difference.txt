Partition a set into two subsets such that the difference of subset sums is minimum

THIS METHOD ONLY WORKS FOR ARRAY WITH +ve ELEMENTS.
As we encounter the negative elements in the given array So there's a possibility 
that our Total Sum or Range becomes negavtive
As soon as our range becomes negative the tabulation method fails because 
it is impossible to create a 2D matrix of size less than 0 i.e NEGATIVE


=================================================================================
Idea:
Let s1 be sum of 1st subset and s2 be sum of 2nd subset
then s1 +s2 =sum of array(S)
so s1=S-s2
We want to minimise s1-s2= S-2*s2

Also In the subset sum problem when we have finally calculated the
matrix the last row has 1 at any sum which can be formed by the elements
of the array.
Thus we can iterate on the last row and find the minimum required.

---------------------------------------------------------------------------
Recursion

int findMinRec(int arr[], int i, int sumCalculated,
               int sumTotal)
{
    // If we have reached last element.  Sum of one
    // subset is sumCalculated, sum of other subset is
    // sumTotal-sumCalculated.  Return absolute difference
    // of two sums.
    if (i == 0)
        return abs((sumTotal - sumCalculated)
                   - sumCalculated);

    // For every item arr[i], we have two choices
    // (1) We do not include it first set
    // (2) We include it in first set
    // We return minimum of two choices
    return min(
        findMinRec(arr, i - 1, sumCalculated + arr[i - 1],
                   sumTotal),
        findMinRec(arr, i - 1, sumCalculated, sumTotal));
}

// Returns minimum possible difference between sums
// of two subsets
int findMin(int arr[], int n)
{
    // Compute total sum of elements
    int sumTotal = 0;
    for (int i = 0; i < n; i++)
        sumTotal += arr[i];

    // Compute result using recursive function
    return findMinRec(arr, n, 0, sumTotal);
}

----------------------------------------------------------------------
Bottom Up

int findMin(int arr[], int n)
{
    // Calculate sum of all elements
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // Create an array to store results of subproblems
    bool dp[n + 1][sum + 1];

    // Initialize first column as true. 0 sum is possible
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;

    // Fill the partition table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If i'th element is excluded
            dp[i][j] = dp[i - 1][j];

            // If i'th element is included
            if (arr[i - 1] <= j)
                dp[i][j] |= dp[i - 1][j - arr[i - 1]];
        }
    }

    // Initialize difference of two sums.
    int diff = INT_MAX;

    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    return diff;
}
