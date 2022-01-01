// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

class graph
{
	int V; 

	list< pair<int, int> > *adj;

public:
	graph(int V); 

	void add_edge(int u, int v, int w);

	void shortest_path(int s);
};

graph::graph(int V)
{
	this->V = V;
	adj = new list<pair<int,int>> [V];
}

void graph::add_edge(int u, int v, int w)
{
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
}

void graph::shortest_path(int src)
{
	priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

	vector<int> dist(V, INF);

	pq.push({0, src});
	dist[src] = 0;

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			int weight = (*i).second;
			if (dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push({dist[v], v});
			}
		}
	}

	for (int i = 0; i < V; ++i)
		cout<<"vertex: "<<i<<"=> shortest ditance from source: "<<dist[i]<<endl;
}

int main()
{
	int V = 4;
	graph g(V);

	g.add_edge(0,1,10);
    g.add_edge(0,2,2);
    g.add_edge(1,3,1);
    g.add_edge(2,3,5);

	g.shortest_path(0);

	return 0;
}
