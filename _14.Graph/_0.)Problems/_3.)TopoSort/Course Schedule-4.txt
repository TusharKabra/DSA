https://leetcode.com/problems/course-schedule-iv/

Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a 
prerequisite of course c, 
then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, 
you should answer whether course uj is a prerequisite of course vj or not.
------------------------------------------------------------------------------------------
ALGO:
We use toposort for marking the nodes. The basic idea is to repeat the process for each node form 0 to n.
Thus for each node i push (i,it) in queue and mark that as reachable.
------------------------------------------------------------------------------------------

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        int n=numCourses;
        vector<vector<int>>adj(n);
        int m=prerequisites.size();
        for(int i=0;i<m;i++)
        {
            int x=prerequisites[i][0];
            int y=prerequisites[i][1];
            adj[x].push_back(y);
        }
        int reach[101][101]={0};  //array to check whether we can reach from some node i to j
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            q.push(i);
            while(!q.empty())
            {
                int x=q.front();
                q.pop();
                for(auto it:adj[x])
                {
                    if(reach[i][it]==1)  //already visited path
                        continue;
                    reach[i][it]=1;
                    q.push(it);
                }
            }
            
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];
            ans.push_back(reach[x][y]==1);
        }
        return ans;
        
        
    }
};

T.C.=O(N^3)