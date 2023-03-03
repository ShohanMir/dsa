#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    
    vector <int> *adj;

public:
    Graph(int v);

    void addEdge(int v, int w);
    void dfs();
    void dfs_utils(int s, vector<bool> &visited);
};

Graph::Graph(int v){
    this->v = v;
    adj = new vector<int>[v];
}

void Graph::addEdge(int v, int w){
    adj[w].push_back(v);
    adj[v].push_back(v);
}

void Graph::dfs() {
    vector <bool>visited(v, false);
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs_utils(i, visited);
        }
    }
}

void Graph::dfs_utils(int s, vector<bool> &visited) {
    visited[s] = true;
    cout<<s<<" ";

    for(vector<int>::iterator itr = adj[s].begin(); itr != adj[s].end(); itr++) {
        if(!visited[*itr])
            dfs_utils(*itr, visited);
    }
}

// Driver code
int main() {
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1, 2);
    g.addEdge(2,0);
    g.addEdge(2, 3); 
    g.addEdge(3, 3);

    cout << "Following is the DFS of the provided Graph: ";
    g.dfs();
    return 0;
}