bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        vector<int> parent(V, -1);//Initially declaring parent as -1
     
        // Create a queue for BFS
        queue<pair<int,int>> q;
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) 
        {
     
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
     
            for (auto it : adj[node]) 
            {
                if (!visited[it]) 
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)  //Checking if this node is not the parent node.Parent node also there in adj list of each node.
				                     //So if node is visted and is not the parent node then cycle.
                    return true;
            }
        }
        return false;
    }


bool isCycle(int V, vector<int>adj[])
{
	vector<int> vis(V, 0); 
	for(int i = 0;i<V;i++) 
	{
		if(!vis[i]) 
		{
			if(checkForCycle(i, V, adj, vis)) return true; 
		}
	}
	
	return false; 
}

