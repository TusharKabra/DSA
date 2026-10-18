https://leetcode.com/problems/network-delay-time/
--------------------------------------------------------------------------------------

TIME AND SPACE COMPLEXITY


Here N is the number of nodes and E is the number of total edges in the given network.

Time complexity: O(N + Elog N)

Finding the minimum time required takes O(N).

The maximum number of vertices that could be added to the priority queue is E. 
Thus, push and pop operations on the priority queue take O(logE) time. 
The value of E can be at most N.(N - 1). Therefore, O(logE) 
is equivalent to O(log N^2) =O(2logN)

Hence, the time complexity for priority queue operations equals O(logN).

Although the number of vertices in the priority queue could be equal to E, we will only visit each vertex only once. 
If we encounter a vertex for the second time, then currNodeTime will be greater than signalReceivedAt[currNode], 
and we can continue to the next vertex in the priority queue. 

Hence, in total E edges will be traversed and for each edge, there could be one priority queue insertion operation.

Hence, the time complexity is equal to O(N+ElogN).
----------------------------------------------------------------
Space complexity: O(N+E)

Building the adjacency list will take O(E) space. Dijkstra's algorithm takes O(E) space 
for priority queue because each vertex could be added to the priority queue N−1 time which makes it N * (N - 1)
and O(N^2) is equivalent to O(E). SignalReceivedAt takes O(N) space.
 
------------------------------------------------------------------------------------------------------- 
class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            int x=times[i][0];
            int y=times[i][1];
            int z=times[i][2];
            adj[x].push_back({y,z});  //adjacent node,distance(edge wt.)
            
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k}); //distance,node
        
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        
        while(!pq.empty())
        {
            auto x=pq.top();
            int dis=x.first;
            int node=x.second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int next=it.first;
                int d=it.second;
                if(dist[next]>dis+d)
                {
                    dist[next]=dis+d;
                    pq.push({dist[next],next});
                }
            }
        }
        
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
                return -1;
            
            mx=max(mx,dist[i]);
        }
        return mx;
        
        
    }
};