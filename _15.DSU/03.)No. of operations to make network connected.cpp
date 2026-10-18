
https://leetcode.com/problems/number-of-operations-to-make-network-connected/


class Solution 
{
public:
    
    int findpar(int u,vector<int>&parent)
    {
        if(parent[u]!=u)
            return parent[u]=findpar(parent[u],parent);
        
        return parent[u];
    }
    void unionn(int u,int v,vector<int>&rank,vector<int>&parent)
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
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        
        int m=connections.size();
        
        vector<int>parent(n);
        vector<int>rank(n,0);
            
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        int c=0;
        int co=0;
        for(int i=0;i<m;i++)
        {
            int x=connections[i][0];
            int y=connections[i][1];
            
            
            if(findpar(x,parent)==findpar(y,parent))
            {
                c++;  //Number of connections which form a cycle. 
				      //We can remove these wires and connect them to the disconnected computers
            }
            else
            {
                co++;  //Number of unique connections which do not form cycle
                unionn(x,y,rank,parent);
            }
                
        }
        if(c+co<n-1) //n-1 are the minimum total connections needed to connect n computers
            return -1;
        else
            return n-1-co;   

    }
};