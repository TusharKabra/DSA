bool isValid(vector<vector<char>>& g,int u,int v,int prex,int prey){
        if (u < 0 || u >= g.size() || v < 0 || v >= g[0].size() || g[u][v] != g[prex][prey]) //if coordinates not valid or the 
        {                                                                                    //previous char not equal to the next character
            return false;
        }
        return true;
    }

    //Function returns true if it detects cycle
    bool bfs(vector<vector<char>>& g,int r,int c,vector<vector<bool>>&vi){
        int offsets[] = {0, 1, 0, -1, 0};
        queue<pair<pair<int,int>,pair<int,int>>>q;     //stores [prevX,prevY],[currX,currY] coordinates
        q.push({{-1,-1},{r,c}});                       //Initially no prev X or Y coordinate so -1,-1
        vi[r][c]=true;                                 
        while(!q.empty()){
            int prex=q.front().first.first;
            int prey=q.front().first.second;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int u = x + offsets[k], v = y + offsets[k + 1];
                if (isValid(g,u,v,x,y)) {                
                    if(vi[u][v]){
                        if(prex!=u or prey!=v){        //Since we cannot go to the coordinate from which we came from
                            return true;               //either the X or the Y coordinate should differ
                        } 
                    }else{
                        vi[u][v] = true;               //else if node isValid and was not visited then push it in the queue
                        q.push({{x,y},{u, v}});
                    }
                }
            }
        }
        return false;      //If queue becomes empty and no cycle detected return false
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    if(bfs(grid,i,j,vis)) return true;
                }
            }
        }
        return false;
    }