https://leetcode.com/problems/redundant-connection/


class Solution {
public:
    
    
    int findpar(int x,vector<int>&parent)
    {
        if(parent[x]!=x)
        {
            return parent[x]=findpar(parent[x],parent);
        }
        
        return x;
    }
    void unionn(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        int x=findpar(u,parent);
        int y=findpar(v,parent);
        
        if(x==y)
            return;
        if(rank[x]<rank[y])
        {
            parent[x]=y;
        }
        else if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        else
        {
            parent[y]=x;
            rank[x]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
       
        int n=edges.size();
        vector<int>parent(n+1,0);
        vector<int>rank(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i]=i;
        
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int x=findpar(u,parent);
            int y=findpar(v,parent);
            if(x==y)
            {
                ans1=u;
                ans2=v;
            }
            else
            {
                unionn(u,v,parent,rank);
            }
            
        }
        return {ans1,ans2};
        
        
    }
};