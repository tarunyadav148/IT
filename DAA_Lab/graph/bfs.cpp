#include<bits/stdc++.h>
using namespace std;

template<typename T>
class graph {
public:
    map<T, list<T>> Adj;
    void add_edge(T u, T v) {
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
};

template<typename T>
void DFS(graph<T> g,T s) {
    //Mark all node as not visited
        static map<T, bool> visited;

        //mark visited for current node
        visited[s] = true;
        cout<<s<<" ";

        for (auto x : g.Adj[s]) {
            if (!visited[x]) {
                DFS(g,x);
            }
        }
}


int main() {
    graph<char> g;
    g.add_edge('A', 'B');
    g.add_edge('A', 'C');
    g.add_edge('B', 'D');
    g.add_edge('C', 'D');
    g.add_edge('D','E');

    DFS<char>(g,'A');

    return 0;
}