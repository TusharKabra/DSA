MST is a tree such that An undirected graph with
weighted edges gets converted into a tree 
//which has all the N nodes 
//has no cycle
//has N-1 edges	
//has the minimum weight for all spanning trees possible


//Idea :Take edge with min weight from all the nodes in your answer unless it makes a cycle																							

Figures out the index with min possible key value not part of mst. Now take this and mark it as true. Now 
check all adj egges and nodes and iterate through them. If not part of mst then take the edge wt and mark this edge wt. and mark the parent but do not include in mst. Just update the key value and parent value. So all adj edges marked in the key. 
Now look for next node which has the min value and mast marked as false and then mark it as true.

 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
    int parent[N]; 
      
    int key[N]; //stores the index, with the help of mst array,
                //we find whether to include this node in MST or not
    bool mstSet[N]; //ititialised to false
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  

    key[0] = 0; 
    parent[0] = -1; // first node does not have any parent
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++) //In MST there will be N-1 edges so we iterate on that.
    { 
        
        int mini = INT_MAX, u; 

        // Trying to figure out which is the minimal key. Iterate from 0 to N and 
        // value not part of MST and store the index in u
        // This node will become part of MST
 
        for (int v = 0; v < N; v++)     //finding the minimal key value not part of mst and store its index
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
                
        mstSet[u] = true; 
        
//Each time we traverse all the adjacent nodes of u 
//If they are already part of MST, then do nothing to them
//and we update the key value of all its adjacent nodes 
//to a smaller value if  possible. However we do not immediately 
//include it in our MST
        
        for (auto it : adj[u])  //iterate for adjacent nodes
        {
            int v = it.first;
            int weight = it.second;

            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    
    for (int i = 1; i < N; i++) //starting from 1 as the initial node has no parent
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}