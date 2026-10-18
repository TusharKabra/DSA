https://leetcode.com/problems/time-needed-to-inform-all-employees/


//a really good question.

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        vector<vector<int>>adj(n);
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
            else
            {
                q.push({i,0});
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int x=q.front().first;
            int t=q.front().second;
            q.pop();
            
            for(auto it: adj[x])
            {
                
                q.push({it,t+informTime[x]});
                ans=max(ans,t+informTime[x]);
            }
        }
        
        return ans;
        
        
        
    }
};