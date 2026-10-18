https://leetcode.com/problems/search-a-2d-matrix-ii/

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

===============================================================

Start from top right corner
===============================================================

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
	{
        int m=matrix.size();
        int n=matrix[0].size();
        int start=matrix[0][n-1];
        int row=0;
        int col=n-1;
        while(row<=m-1&&col>=0)
        {
            if(target==matrix[row][col])
                return true;
            if(target>matrix[row][col])
                row++;
            else
                col--;
        }
        return false;
    }
};