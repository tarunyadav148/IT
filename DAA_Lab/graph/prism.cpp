#include<bits/stdc++.h>
using namespace std;

# define INF 0x3f3f3f3f
 
class graph
{
    int V;    // No. of vertices
    list< pair<int, int> > *adj;
public:
    graph(int V);  
    void add_edge(int u, int v, int w);
    void prim_minimum_spanning_tree();
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
 

void graph::prim_minimum_spanning_tree()
{

    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    int src = 0; 
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
 
    pq.push({0, src});
    key[src] = 0;
 
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
         
        if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true; 
 
        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;
 
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
 
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<< i<<endl;
}
 
int main()
{
    int V = 4;
    graph g(V);
 
    g.add_edge(0,1,10);
    g.add_edge(0,2,2);
    g.add_edge(1,3,1);
    g.add_edge(2,3,5);
 
    g.prim_minimum_spanning_tree();
 
    return 0;
}