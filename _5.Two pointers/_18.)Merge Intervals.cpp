

https://leetcode.com/problems/merge-intervals/


class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int curx=intervals[0][0];
        int cury=intervals[0][1];
        vector<vector<int>>ans;
        
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=cury)   //..
            {
                cury=max(intervals[i][1],cury);

            }
            else
            {
                
                ans.push_back({curx,cury});
                curx=intervals[i][0];
                cury=intervals[i][1];
                
            }
        }
        
        ans.push_back({curx,cury});
        return ans;
            
    }
};