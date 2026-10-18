https://leetcode.com/problems/interval-list-intersections/



https://leetcode.com/problems/interval-list-intersections/discuss/2120196/Simple-solution-with-proper-thought-process 
Read this first.Good soln.

Possible cases of intersection:
For X  coordinate:
1.)
 -------------
    ----------
	
2.)
   ----------
-------------

For Y coordinate:
1.)
-------------
---------
2.)
---------
-------------	

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int i=0;
        int j=0;
        vector<vector<int>>ans;
        if(A.size()==0||B.size()==0)
            return ans;
        
        while(i<A.size()&&j<B.size())
        {
            int lo=max(A[i][0],B[j][0]); //MAX of X coordinate
            int hi=min(A[i][1],B[j][1]); //Min of Y coordinate
            if(lo<=hi)
            {
                ans.push_back({lo,hi});
                
            }
            if(A[i][1]<B[j][1]) //Basically intersection with the element i in array A is complete so move the i pointer.
                i++;
            else
                j++;
        }
        
        return ans;
    }
};