https://leetcode.com/problems/course-schedule-iii/


courses[i] = [durationi, lastDayi]
Return the maximum number of courses that you can take.

==============================================================
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1]; //sorted according to last day
    }
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        int n=courses.size();
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<pair<int,int>>pq;
        int timer=0;
        
        for(int i=0;i<n;i++)
        {
            pq.push({courses[i][0],courses[i][1]});
            timer+=courses[i][0];
            if(timer>courses[i][1])
            {
                timer=timer-pq.top().first;
                pq.pop();
            }
            
        }
        return pq.size();
        
    }
};