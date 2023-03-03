#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// DFS(G)
// 1 for each vertex u 2 G:V
// 2    u:color D WHITE
// 3    u: D NIL
// 4 time D 0
// 5 for each vertex u 2 G:V
// 6    if u:color = = WHITE
// 7        DFS-V ISIT.G; u/
// DFS-VISIT(G, u)/
// 1 time D time C 1 // white vertex u has just been discovered
// 2    u:d D time
// 3    u:color D GRAY
// 4 for each  2 G:AdjŒu // explore edge .u; /
// 5    if :color = = WHITE
// 6        : D u
// 7        DFS-V ISIT.G; /
// 8 u:color D BLACK // blacken u; it is finished
// 9 time D time C 1
// 10 u:f D time
// Figure 22.4 illustrates the progress of DFS on the graph shown in Figure 22.2.
// Procedure DFS works as follows. Lines 1–3 paint all vertices white and ini-
// tialize their  attributes to NIL . Line 4 resets the global time counter. Lines 5–7
// check each vertex in V in turn and, when a white vertex is found, visit it using
// DFS-V ISIT . Every time DFS-V ISIT.G; u/ is called in line 7, vertex u becomes


class Graph {
    int V;

    vector <int> *adj;
public:
    Graph(int V);

    void addEdge(int v, int w);
    void dfs();
    void dfs_utils(int s, vector<bool>&visited);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[w].push_back(v);
    adj[v].push_back(w);
}

void Graph::dfs() {
    vector<bool>visited(V, false);
    for(int i = 0; i < V; i++)
        if(!visited[i])
            dfs_utils(i, visited);
}

void Graph::dfs_utils(int s, vector<bool> &visited){
    visited[s] = true;
    cout << s << " ";

    vector<int>::iterator itr;
    for(itr = adj[s].begin(); itr != adj[s].end(); itr++) {
        if(!visited[*itr])
            dfs_utils(*itr, visited);
    }
}


int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2, 3); 
    g.addEdge(3, 3);

    cout << "Following its the DFS of the provided Graph" << "(starting from vertex 0): "<< endl;
    g.dfs();

    return 0;
}