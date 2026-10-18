https://leetcode.com/problems/search-a-2d-matrix/

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row

=======================================================================
Procedure:
Binary search on 1st column to find element less than or equal to target.(Store the index)
Search in this row(index) for the target.


class Solution {
public:
    int searchRowIndex(vector<vector<int>>&matrix,int target)
    {
        int lo=0;
        int hi=matrix.size()-1;
        int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(matrix[mid][0]==target)
                return mid;
            if(matrix[mid][0]<target)
            {
                ans=mid;
                lo=mid+1;
            }
            else
                hi=mid-1;
        }
        return ans;
    }
    
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int x=searchRowIndex(matrix,target);
        if(x==-1)
            return false;

        int y=lower_bound(matrix[x].begin(),matrix[x].end(),target)-matrix[x].begin();
        if(y<0||y>=matrix[0].size())
            return false;
        return (matrix[x][y]==target);
        
        
    }
};