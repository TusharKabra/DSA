//gives shortest path from src to node and works for negative edge.
//For dijkstra, if negative edges then the distance reduces and a cycle would occur.


//Bellman ford does not work for negative cycles in both directed/undirected graph. 
However it will tell if negative cycle present or not.
Bellman does not work for directed graph for negative cycles(sum of edges is negative).
For undirected graph,convert to directed using bidirectional edges.