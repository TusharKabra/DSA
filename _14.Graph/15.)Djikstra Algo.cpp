//Calculates shortest distance in weighted directed/undirected graph from src to target node.
//Can handle cycles
//Cannot handle negative cycles.



#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for graph

	int a,b,wt;
	for(int i = 0; i<m ; i++)
	{
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
    // Node with the min. dist should always be at the top of the priority queue

	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        // min-heap ; In pair => (dist,from)

	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() )
    {
		int dist = pq.top().first; 
		int prev = pq.top().second; 
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++)
        {
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist)
            {
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}

=================================================================================
TIME COMPLEXITY ANALYSIS

1.)The pq can have all the vertices so it will have V vertices.
2.)The pq.pop() operation is log(Heap size)
3.)Consider a dense graph where each node is connected to the other node.
Then we will have V-1 edges for each node.

TC= O(V*[log(heap size)+number of edges*(log(heap size))])
=O(V*[(number of edges+1)*(log of heap size)]
=O(V*(V-1+1)*(log(V^2)))
=O(V^2* (2logV))

E=V^2
because if each node is connected to V-1 nodes, then each node has V-1 edges
Therefore total edges is roughly V^2

So
TC=O(2E log(V))

