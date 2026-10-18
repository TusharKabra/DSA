https://leetcode.com/problems/max-points-on-a-line/


can see this:
https://leetcode.com/problems/max-points-on-a-line/discuss/47124/C%2B%2B-slope-counter
==========================================================================================
Techniques:
*Tricky to handle duplicates.

*Take difference between points x and y coordinate (dx and dy) and then 
divide dx and dy by gcd of(dx,dy). Also Hash it as mp[dx_dy] by converting dx_dy to string.

int dx = points[j].x - points[i].x;
int dy = points[j].y - points[i].y;
int g = __gcd(dx, dy);
counter[to_string(dx / g) + '_' + to_string(dy / g)]++;

//gcd(0,a)=a where a>0 so g will be 0 only if the two points 
are identical and it is given that points are unique


=================================================================
//code also handles the base case of n==1 here we have only one point and so ans will be 1.

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        
        int mx=0;//max no. of same slopes
        for(int i=0;i<n;i++)
        {
            unordered_map<string,int>mp;
            for(int j=i+1;j<n;j++)
            {
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int diffX=x2-x1;
                int diffY=y2-y1;
                int g=(__gcd(diffX,diffY)); 
                string key=to_string(diffX/g)+"_"+to_string(diffY/g);
                mp[key]++;
                mx=max(mx,mp[key]);
            }
        }
        return mx+1;
        
    }
};
=================================================================
Code to handle duplicates as well:

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size(), ans = 0;
        for (int i = 0; i < n; i++) 
		{
            unordered_map<string, int> counter;
            int dup = 1;
            for (int j = i + 1; j < n; j++) 
			{
                if (points[j].x == points[i].x && points[j].y == points[i].y) 
				{
                    dup++;
                } 
				else 
				{
                    int dx = points[j].x - points[i].x, dy = points[j].y - points[i].y, g = gcd(dx, dy);
                    counter[to_string(dx / g) + '_' + to_string(dy / g)]++;
                }
            }
            ans = max(ans, dup);
            for (auto p : counter) {
                ans = max(ans, p.second + dup);
            }
        }
        return ans;
    }
private:
    int gcd(int a, int b) {
        while (b) {
            a = a % b;
            swap(a, b);
        }
        return a;
    }
};