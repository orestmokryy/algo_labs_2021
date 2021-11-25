This is the implementation of Bellman-Ford algorithm. 
It's purpose is to search the lightest path in the graph between a source vertice and all other vertices. 

To create an edge use 
  graph->edge[1].src = number; where number is the source vertice of the edge
	graph->edge[1].dest = number; where number is the destination vertice of the edge
	graph->edge[1].weight = number; where number is the weight of the edge
  
After you created enough edges you can all the searching algorithm with this line 

  BellmanFord(graph, number); where number is the source vertice.
  
After you've run the program it will print the results like this :
Vertex Distance from Source
0                0 
1                -1
2                4 
3                1 
4                6

Where the first colunm is the destination vertice, and the second one is weight of the shortest path from source vertice to destination vertice.
