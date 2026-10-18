//Use three colors 0,1,2
//vis[i]=0,1,2 (Unvisited,unsafe,safe)
//initialise with 0

bool directedCycle(ll u)
{
    vis[u] = 1; //initially marked unsafe

    for(ll i: adj[u]){
        if(vis[i] == 1){
            return true;
        } else if(vis[i] == 0){
            if(directedCycle(i)) return true;
        }
    }
    vis[u] = 2;
    return false;
}
 