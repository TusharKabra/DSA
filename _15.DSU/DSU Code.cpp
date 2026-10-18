//DO HAVE A LOOK AT THE BELOW SECTION

Method1:
    //First Initialise parent array with i and rank array with 0;
    // Finds set of given item x
    int find(int x)
    {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {
  
            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,                                                   
            parent[x] = find(parent[x]);
  
            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }
  
        return parent[x];
    }
  
    // Do union of two sets represented
    // by x and y.
    void Union(int x, int y)
    {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);
  
        // If they are already in same set
        if (xset == yset)
            return;
  
        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        }
  
        // If ranks are same, then increment
        // rank.
        else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;  //height of the tree inc only when attaching two same ranked guys
        }
    }



METHOD 2:
 int findpar(int x,int parent[])
    {
        if(parent[x]==x)
            return x;
        
        if(parent[x]!=x)
            parent[x]=findpar(parent[x],parent);
        
        return parent[x];
    }
    void unionn(int x,int y,int parent[],int rank[])
    {
        x=findpar(x,parent);
        y=findpar(y,parent);
        if(rank[x]>rank[y])
        {
            parent[y]=x;
        }
        else if(rank[y]>rank[x])
        {
            parent[x]=y;
        }
        else
        {
            parent[y]=x;
            rank[x]++;
        }
    }
 


 
In main function:  

for(int i=1;i<=n;i++)
           parent[i]=i;
    
        int rank[200000]={0};
		
		
		
when creating  graph do this:

while(m--)
{
int u,v;
cin>>u>>v;
union(u,v);

}
findpar(2)!=findpar(3)//to check if in same component.	