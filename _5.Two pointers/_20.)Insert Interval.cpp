https://leetcode.com/problems/insert-interval/


EXAMPLE:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
---------------------------------------------------------------

class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        
        int x=newInterval[0];
        int y=newInterval[1];
        bool flag=true;
        intervals.push_back({x,y});
        sort(intervals.begin(),intervals.end());
        
        int n=intervals.size();
        int curx=intervals[0][0];
        int cury=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<=cury)
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


--------------------------------------------------------------------
OPTIMAL SOLUTION:
O(N) Solution:

Procedure:
1.) Array before the insertion was already in the non-overlapping form.
2.) We reach the y coordinate of our array which is  less than the x 
coordinate of the interval we are inserting.Till this point, everything remains 
same. So we push it in our ans array as it is.
3.) Case2: is the main merging step. 
4.) Case3: deals with the array left to the right after merging 
which would also remain as it is


class Solution 
{
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
   {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;
		
        //case 1: no overlapping case before the merge intervals
		//compare ending point of intervals to starting point of newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }                   
        
		//case 2: overlapping case and merging of intervals
        while(i < n && newInterval[1] >= intervals[i][0])
		{
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
		
        // case 3: no overlapping of intervals after newinterval being merged
        while(i < n)
		{
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};