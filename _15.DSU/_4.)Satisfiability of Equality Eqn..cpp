https://leetcode.com/problems/satisfiability-of-equality-equations/

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

---------------------------------------------------------------------------------------

class Solution {
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
    bool equationsPossible(vector<string>& equations) 
    {
        int n=equations.size();
        vector<int>parent(27,0);
        for(int i=0;i<26;i++)
            parent[i]=i;
        vector<int>rank(26,0);
        for(int i=0;i<n;i++)
        {
            string x=equations[i];
            if(x[1]=='=')
            {
                unionn(x[0]-'a',x[3]-'a',rank,parent);
            }
 
        }
        for(int i=0;i<n;i++)
        {
            string x=equations[i];
            if(x[1]=='!')
            {
                if(findpar(x[0]-'a',parent)==findpar(x[3]-'a',parent))
                    return false;
            }
        }
        return true;
        
    }
};