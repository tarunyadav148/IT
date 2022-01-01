#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
	int u, v, w;
};


class Graph {
public:
	
	int V, E;

	Edge* edge;
};

Graph* make_graph(int V, int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}

class DisjointSet {
public:
	int parent;
	int rank;
};

int find(DisjointSet subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent
			= find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

void Union(DisjointSet subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;

	else {
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int myComp(const void* a, const void* b)
{
	Edge* a1 = (Edge*)a;
	Edge* b1 = (Edge*)b;
	return a1->w > b1->w;
}

void kurskal_MST(Graph* graph)
{
	int V = graph->V;
	Edge result[V];
	int e = 0; 
	int i = 0; 

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
		myComp);

	DisjointSet* subsets = new DisjointSet[(V * sizeof(DisjointSet))];

	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < V - 1 && i < graph->E)
	{
		Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.u);
		int y = find(subsets, next_edge.v);

		if (x != y) {
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}

	int min_cost = 0;
	for (i = 0; i < e; ++i)
	{
		cout <<"edge: " << result[i].u << " -- " << result[i].v
			<< " and cost=> " << result[i].w << endl;
		min_cost = min_cost + result[i].w;
	}
	cout << "Cost of Minimum Cost Spanning Tree: " << min_cost
		<< endl;
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
	
	kurskal_MST(graph);

	return 0;
}

