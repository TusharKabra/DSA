https://www.geeksforgeeks.org/given-sorted-dictionary-find-precedence-characters/

ALGO
Compare each 2 adjacent words and create an edge from the first unequal char between the two and break.
Then do toposort.

class Solution{
    public:
    
    void dfs(vector<int>&vis,string &x,vector<vector<int>>&adj,int i)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                dfs(vis,x,adj,it);
            }
        }
        x+=char(i+'a');
    }
    string findOrder(string dict[], int N, int K) 
    {
        vector<vector<int>>adj(K);
        
        for(int i=1;i<N;i++)
        {
            string a=dict[i];
            string b=dict[i-1];
            for(int j=0;j<min(a.length(),b.length());j++)
            {
                if(a[j]!=b[j])
                {
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    break;
                }
                
            }
        }
        string x="";
        vector<int>vis(K,0);
        for(int i=0;i<K;i++)
        {
            if(!vis[i])
            {
                dfs(vis,x,adj,i);
            }
        }
        
        return x;
    }
};

--------------------------------------------------------------------------------------