#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph{
    int v;

    vector <int> *adj;

public:
    Graph(int v);

    void add_edge(int v, int u);
    void dfs();
    void dfs_util(int s, vector <bool>&visited);
};

Graph::Graph(int v){
    this->v = v;
    adj = new vector <int>[v];
}

void Graph::add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(v);
}

void Graph::dfs() {
    vector <bool>visited(v, false);
    for(int i = 0; i < v; i++)
        if(!visited[i])
            dfs_util(i, visited);
}

void Graph::dfs_util(int s, vector <bool> &visited){
    visited[s] = true;
    cout << s << " ";

    for(vector <int>::iterator itr = adj[s].begin(); itr!=adj[s].end(); itr++) {
        if(!visited[*itr])
            dfs_util(*itr, visited);
    }
}

int main() {
    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1,2);
    g.add_edge(2,0);
    g.add_edge(2, 3); 
    g.add_edge(3, 3);

    cout << "Following its the DFS of the provided Graph" << "(starting from vertex 0): ";
    g.dfs();

    return 0;
}