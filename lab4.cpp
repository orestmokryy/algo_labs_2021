#include <bits/stdc++.h>

struct Edge {
	int src, dest, weight;
};

struct Graph {

	int Vertices, Edges;

	struct Edge* edge;
};

struct Graph* createGraph(int Vertices, int Edges)
{
	struct Graph* graph = new Graph;
	graph->Vertices = Vertices;
	graph->Edges = Edges;
	graph->edge = new Edge[Edges];
	return graph;
}
void printResults(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < n; ++i)
		printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(struct Graph* graph, int src)
{
	int Vertices = graph->Vertices;
	int Edges = graph->Edges;
	int dist[Vertices];


	for (int i = 0; i < Vertices; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	for (int i = 1; i <= Vertices - 1; i++) {
		for (int j = 0; j < Edges; j++) {
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}

	for (int i = 0; i < Edges; i++) {
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
			printf("Graph contains negative weight cycle");
			return;
		}
	}

	printResults(dist, Vertices);

	return;
}

int main()
{

	int Vertices  = 5; 
	int Edges = 8;
	struct Graph* graph = createGraph(Vertices, Edges);

	
	graph->edge[0].src = 0; //source Vertice
	graph->edge[0].dest = 1; // destination Vertices
	graph->edge[0].weight = -1; // take a wild guess on what this is

	BellmanFord(graph, 0); //where the int is the source vertice

	return 0;
}
