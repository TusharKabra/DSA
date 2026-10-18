//For strongly connected component in directed graph

//Strongly connected means that every node is 
//reachable from every other node

// Helps to group node of one SCC together

//Intuition:Reverse dfs as single component scc(only one element) 
//should be traversed first


//METHOD:
//Sort all nodes according to finish time(Topo sort)
//Then transpose the graph i.e all the edges will be reversed. 
//Now dfs would only let us remain in the SCC
//Now do DFS according to finish time on the transposed graph



#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m; 

//Directed graph
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}
	

//Topo Sort insertion
	stack<int> st;
	vector<int> vis(n, 0); 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 


//Transpose Graph
	
	vector<int> transpose[n]; 
	
	for(int i = 0;i<n;i++) {
	    vis[i] = 0; //Remark visited as 0
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	    }
	}
	
	
// Go on the nodes according to their finish time 
//and if unvisited call the reverse dfs

	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	
	
	return 0;
}
