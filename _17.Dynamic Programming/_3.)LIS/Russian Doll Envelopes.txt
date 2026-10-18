https://leetcode.com/problems/russian-doll-envelopes/ 

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] 
represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height 
of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
-------------------------------------------------------------------------
ALGO
Sort the envelopes in ascending order of widths and if 
widths are equal then in descending order of heights.

Then Apply LIS on heights.

-------------------------------------------------------------------------
why descending order of height?

Consider this-
[[4,5],[4,6],[6,7],[2,3],[1,1]]

Correct ans is 4 as we cannot include both the width 4 letters, only one of them.

sorted in width(ascending order) and height(descending)
[[1,1],[2,3],[4,6],[4,5],[6,7]]
This would give ans as 4

sorted in width(ascending order) and height(ascending)
[[1,1],[2,3],[4,5],[4,6],[6,7]]
This would give ans as 5


Consider this case as well-
[[4,5],[4,6],[6,6],[2,3],[1,1]]
The correct ans is 4
-----------------------------------------------------------------------------

class Solution {
public:
    static bool cmp(vector<int>&x,vector<int>&y)
    {
        if(x[0]==y[0])
            return y[1]<x[1];
        return x[0]<y[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        if(envelopes.size()==0)
            return 0;
        sort(envelopes.begin(),envelopes.end(),cmp);
        int n=envelopes.size();
        vector<int>temp;
        temp.push_back(envelopes[0][1]);
        
        for(int i=1;i<n;i++)
        {
            if(envelopes[i][1]>temp[temp.size()-1])
                temp.push_back(envelopes[i][1]);
            else
            {
                auto it=lower_bound(temp.begin(),temp.end(),envelopes[i][1]);
                *it=envelopes[i][1];
            }
               
        }
        return temp.size();
            
    }
};