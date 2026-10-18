#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//sort(arr, arr + n, greater<int>()); 
//cout<<fixed<<setprecision(20)<<(double)(result)<<endl;
 
void dfs(int u,int v,vector<vector<int>>adj,vector<int>&sz)
{
    sz[u]=1;    //initialise as 1
    for(auto it: adj[u])
    {
        if(it!=v)                //dont take the current nodes parent into account
        {
            dfs(it,u,adj,sz);    //it becomes the child node and u becomes the parent now
            sz[u]+=sz[it];      //add the size of subtree in the parent node
        }
    }
}
int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int m=n-1;
        vector<vector<int>>adj(n);
        while(m--)
        {
            int u;int v;
            cin>>u>>v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        vector<int>sz(n,0);
        dfs(0,-1,adj,sz);
        for(int i=0;i<n;i++)
        cout<<sz[i]<<" ";
    }
}

        