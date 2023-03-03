#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;

    vector <int> *adj;

public:
    Graph(int V);

    void add_edge(int v, int w);
    void dfs();
    void dfs_util(int s, vector <bool>&visited);
    void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new vector <int>[V];
}

void Graph::add_edge(int v, int w) {
    adj[w].push_back(v);
    adj[v].push_back(w);
}

void Graph::dfs() {
    vector <bool>visited(V, false);
    for(int i = 0; i < V; i++) {
        if (!visited[i])
            dfs_util(i, visited);
    }
}

void Graph::dfs_util(int s, vector <bool>&visited) {
    visited[s] = true;
    cout << s << " ";
    vector <int>::iterator itr;
    for(itr = adj[s].begin(); itr != adj[s].end(); itr++) {
        if(!visited[*itr]) {
            dfs_util(*itr, visited);
        }
    }
}

void Graph::BFS(int s) {
    vector<bool> visited;
    visited.resize(V, false);

    list<int> que;

    visited[s] = true;
    que.push_back(s);

    while(!que.empty()) {
        s = que.front();
        cout << s << " ";
        que.pop_front();

        for(auto adjacent: adj[s]) {
            if(!visited[adjacent]) {
                visited[adjacent] = true;
                que.push_back(adjacent);
            }
        }
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

    cout << "Following its the DFS of the provided Graph" << "(starting from vertex 0): " << endl;
    g.dfs();

    cout << endl;

    cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2)" << endl;
	g.BFS(2);

    return 0;
}