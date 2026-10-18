https://www.geeksforgeeks.org/cutting-a-rod-dp-13/

Optimised:

Method 1:
/* Returns the best obtainable price for a rod of length n and
   price[] as prices of different pieces */
int cutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;

   // Build the table val[] in bottom up manner and return the last entry
   // from the table
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }

   return val[n];
}

------------------------------------------------------------------------------

Method2: Memoization
Using unbounded Knap


// A recursive program, using ,
// memoization, to implement the
// rod cutting problem(Top-Down).
int un_kp(int price[], int length[], 
                    int Max_len, int n)
{

    // The maximum price will be zero,
    // when either the length of the rod
    // is zero or price is zero.
    if (n == 0 || Max_len == 0) 
    {
        return 0;
    }

    // If the length of the rod is less
    // than the maximum length, Max_lene will
    // consider it.Now depending 
    // upon the profit,
    // either Max_lene  we will take 
    // it or discard it.
    if (length[n - 1] <= Max_len) 
    {
        t[n][Max_len]
            = max(price[n - 1]
                      + un_kp(price, length,
                           Max_len - length[n - 1], n),
                  un_kp(price, length, Max_len, n - 1));
    }

    // If the length of the rod is
    // greater than the permitted size,
    // Max_len we will  not consider it.
    else 
    {
        t[n][Max_len]
            = un_kp(price, length, 
                              Max_len, n - 1);
    }

    // Max_lene Max_lenill return the maximum
    // value obtained, Max_lenhich is present
    // at the nth roMax_len and Max_lenth column.
    return t[n][Max_len];
}
-------------------------------------------------------------
DP

intitialise the first row and column with 0;
t[n+1][length of array+1] //length of array is better than length of rod as 
                          //in some cases we can cut rod in only some fixed dimensions

wt[]->length[]
val[]->price[]
W->N


if(length[i-1]<=j)
t[i][j]=max(price[i-1]+t[i][j-length[i-1],t[i-1][j])

else
t[i][j]=t[i-1][j]

----------------------------------------------------------------







