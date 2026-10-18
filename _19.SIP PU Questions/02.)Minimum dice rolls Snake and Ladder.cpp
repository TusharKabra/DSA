https://www.geeksforgeeks.org/snake-ladder-problem-2/
https://www.hackerrank.com/contests/pu-coding-test-2022/challenges/the-quickest-way-up/problem


LOGIC:
Make an undireced graph and use another array/map to update the snake and ladder cells. 
Then make an adjacency list and use BFS shortest path algo for unweighted directed graph from src to final node.
---------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>

using namespace std;


/*
 * Complete the 'quickestWayUp' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY ladders
 *  2. 2D_INTEGER_ARRAY snakes
 */



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>moves(101,-1);
        
        //LADDERS
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            moves[x]=y;
        }
        
        //SNAKES
        int m;
        cin>>m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            moves[x]=y;
        }
        
        vector<int>dist(101,1e9);
        vector<vector<int>>adj(101);
        
        for(int i=1;i<=100;i++)
        {
            for(int j=i+1;j<=min(i+6,100);j++)
            {
                int next=j;
                if(moves[next]!=-1)
                    next=moves[next];
                adj[i].push_back(next);
            }
        }
        queue<int>q;
        q.push(1); //src node
        dist[1]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(dist[it]>dist[node]+1)
                {
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        if(dist[100]==1e9)
            cout<<-1<<endl;
        else
            cout<<dist[100]<<endl;
    }
}
