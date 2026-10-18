https://leetcode.com/problems/triangle/

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

=====================================================
Consider triangle like this instead-
2
3 4
6 5 7
4 1 8 3

======================================================
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<int>minDist(triangle.back());
        int n=triangle.size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                minDist[j]=min(minDist[j],minDist[j+1])+triangle[i][j];
            }
        }
        
        return minDist[0];
        
    }
};