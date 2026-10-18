https://leetcode.com/problems/minimum-area-rectangle/

Observation:
Focus on the diagonals of the rectangle. If we have a diagonal formed by two points x1,y1 and x2,y2 
then we must have x1,y2 and x2,y1 in our points array to form the rectangle

=========================================================
Procedure:
1.)Insert all points in a map of unordered set.
2.)Use a map with key as the x coordinate and the unordered set should 
have all the y coordinates which come with this value of x.
=======================================================================
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) 
    {
        int n=points.size();
        unordered_map<int,unordered_set<int>>mp;
        int res=1e9;
        for(int i=0;i<n;i++)
        {
            mp[points[i][0]].insert(points[i][1]);
        }
        
        for(int i=0;i<n;i++)
        {
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<n;j++)
            {
                
                int x2=points[j][0];
                int y2=points[j][1];
                
                if(mp[x1].count(y2)&&mp[x2].count(y1))
                {
                    int area=abs(x2-x1)*abs(y2-y1);
                    if(area>0)
                    {
                        res=min(res,area);
                    }
                }
                
            }
        }
        if(res==1e9)
            return 0;
        else return res;
    }
};
