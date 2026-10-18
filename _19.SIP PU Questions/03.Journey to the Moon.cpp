//basic count of connected components question

#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */


void dfs(vector<vector<long long int>>&adj,long long int i,vector<long long int>&vis,int &count)
{
    vis[i]=1;
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            count++;
            dfs(adj,it,vis,count);
        }
    }
}


int main()
{
    long long int n,p;
    cin>>n>>p;
    
    
    
    vector<vector<long long int>>adj(n);
    
    for(int i=0;i<p;i++)
    {
        long long int x,y;
        cin>>x>>y;
        
        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<long long int>vis(n,0);
    int c=0;
    vector<long long int>ans;
     long long int sum=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            c++;
            int count=1;
            dfs(adj,i,vis,count);
            ans.push_back(count);
            sum+=count;
            
        }
    }
    if(c==1)
    {
        cout<<0<<endl;
    }
    else
    {
        long long int x=0;
        for(int i=0;i<ans.size();i++)
        {
            x=x+ans[i]*(n-ans[i]);
        }
         cout<<x/2<<endl;
    }
    
}

    
    