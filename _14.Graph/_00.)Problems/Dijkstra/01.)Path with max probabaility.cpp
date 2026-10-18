https://leetcode.com/problems/path-with-maximum-probability/

class Solution 
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)     {
        
        
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            
            int x=edges[i][0];
            int y=edges[i][1];
            adj[x].push_back({y,succProb[i]});
            adj[y].push_back({x,succProb[i]});
            
        }
        
        priority_queue<pair<double,int>>pq;     //want max prob at top
        pq.push({1.0,start});
        
        vector<double>prob(n,(double)(0.0));
        prob[start]=1.0;
        
        while(!pq.empty())
        {
            double pr=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                
                if(prob[it.first]<it.second*pr)
                {
                    
                    prob[it.first]=it.second*pr;
                    pq.push({prob[it.first],it.first});
                    
                }
            }
        }
        return prob[end];
        
        
    }
};