https://www.geeksforgeeks.org/submatrix-sum-queries/

Q)Find sum between two cells in O(1) time for the given queries.
----------------------------------------------------------
ALGO
Create a matrix and add prefix column sum.
Then add row sums.
Sum between (tli, tlj) and (rbi, rbj) is,
   aux[rbi][rbj] - aux[tli-1][rbj] - 
   aux[rbi][tlj-1] + aux[tli-1][tlj-1]

The submatrix aux[tli-1][tlj-1] is added because  
elements of it are subtracted twice.
----------------------------------------------------------
EXAMPLE:
We first preprocess the matrix and build
following aux[M][N]
aux[M][N] = {1,  3,   6,  10, 16}
            {6,  11,  22, 27,  35},
            {10, 21,  39, 49,  62},  
            {12, 27,  53, 72,  89} }

Query : tli = 2, tlj = 2, rbi = 3, rbj = 4  
      
Sum between (2, 2) and (3, 4) = 89 - 35 - 27 + 11
                              = 38
----------------------------------------------------------------         
int preProcess(int mat[M][N], int aux[M][N])
{
   // Copy first row of mat[][] to aux[][]
   for (int i=0; i<N; i++)
      aux[0][i] = mat[0][i];
 
   // Do column wise sum
   for (int i=1; i<M; i++)
      for (int j=0; j<N; j++)
         aux[i][j] = mat[i][j] + aux[i-1][j];
 
   // Do row wise sum
   for (int i=0; i<M; i++)
      for (int j=1; j<N; j++)
         aux[i][j] += aux[i][j-1];
}
 
// A O(1) time function to compute sum of submatrix
// between (tli, tlj) and (rbi, rbj) using aux[][]
// which is built by the preprocess function
int sumQuery(int aux[M][N], int tli, int tlj, int rbi,
                                              int rbj)
{
    // result is now sum of elements between (0, 0) and
    // (rbi, rbj)
    int res = aux[rbi][rbj];
 
    // Remove elements between (0, 0) and (tli-1, rbj)
    if (tli > 0)
       res = res - aux[tli-1][rbj];
 
    // Remove elements between (0, 0) and (rbi, tlj-1)
    if (tlj > 0)
       res = res - aux[rbi][tlj-1];
 
    // Add aux[tli-1][tlj-1] as elements between (0, 0)
    // and (tli-1, tlj-1) are subtracted twice
    if (tli > 0 && tlj > 0)
       res = res + aux[tli-1][tlj-1];
 
    return res;
}