#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u, v, w;
};

struct Graph {
	int V, E;

	struct Edge* edge;
};

struct Graph* make_graph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}


void printDistances(int dist[], int n)
{
	for (int i = 0; i < n; ++i)
		cout<<"vertex: "<<i<<" => shortest ditance from source: "<<dist[i]<<endl;
}


void BellmanFord(struct Graph* graph, int u)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[u] = 0;

	for (int i = 1; i <= V - 1; i++) {
		for (int j = 0; j < E; j++) {
			int u = graph->edge[j].u;
			int v = graph->edge[j].v;
			int w = graph->edge[j].w;
			if (dist[u] != INT_MAX && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	for (int i = 0; i < E; i++) {
		int u = graph->edge[i].u;
		int v = graph->edge[i].v;
		int w = graph->edge[i].w;
		if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
			printf("Graph contains negative w cycle");
			return; 
		}
	}

	printDistances(dist, V);

	return;
}


int main()
{
	int V = 4; 
	int E = 4; 
	Graph* graph = make_graph(V, E);

	graph->edge[0].u = 0;
	graph->edge[0].v = 1;
	graph->edge[0].w = 10;

	graph->edge[1].u = 0;
	graph->edge[1].v = 2;
	graph->edge[1].w = 2;

	graph->edge[2].u = 1;
	graph->edge[2].v = 3;
	graph->edge[2].w = 1;

	graph->edge[3].u = 2;
	graph->edge[3].v = 3;
	graph->edge[3].w = 5;

	BellmanFord(graph, 0);

	return 0;
}
