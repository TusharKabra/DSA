https://leetcode.com/problems/critical-connections-in-a-network/


class Solution {
public:
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<vector<int>>&adj,vector<vector<int>>&ans) 
{
    vis[node] = 1; 
    tin[node] = low[node] = timer++; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj,ans); 
            low[node] = min(low[node], low[it]); 
            if(low[it] > tin[node]) 
            {
                ans.push_back({node,it});
                
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++)
        {
            int x=connections[i][0];
            int y=connections[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<vector<int>>ans;
        vector<int> tin(n, -1);//Time of insertion
	    vector<int> low(n, -1); //Lowest time of insertion
        vector<int> vis(n, 0); 
        int timer = 0;   
        for(int i = 0;i<n;i++) 
        {
            if(!vis[i]) 
            {
                dfs(i, -1, vis, tin, low, timer, adj,ans); 
            }
        }
       
        return ans;
        
        
    }
};