https://leetcode.com/problems/course-schedule-ii/

The pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. 
If there are many valid answers, return any of them. If it is impossible to finish all courses, 
return an empty array.



class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int n=numCourses;
        vector<vector<int>>adj(n);
        int m=prerequisites.size();
        vector<int>indegree(n,0);
        for(int i=0;i<m;i++)
        {
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            adj[y].push_back(x);
            indegree[x]++;
            
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(auto it:adj[x])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
            
        }
        if(ans.size()!=n)
            return {};
        else
            return ans;

    }
};