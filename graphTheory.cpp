// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
	map<int, bool> visited;
	map<int, list<int> > adj;

	// function to add an edge to graph
	void addEdge(int v, int w);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v);

	void BFS(int s);
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}


//Depth first search
void Graph::DFS(int v)
{
	// Mark the current node as visited and
	// print itn
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFS(*i);
}

//Breath first search
void Graph::BFS(int v){
	// visited<bool> visited;
	// visited.resize(v, false);
	list<int> queue;

	visited[v] = true;
	queue.push_back(v);

	while(!queue.empty()) {
		v = queue.front();
		cout << v << " ";
		queue.pop_front();

		for(auto adjecent: adj[v]) {
			if(!visited[adjecent]){
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
}

// Driver's code
int main()
{
	// Create a graph given in the above diagram
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n";

	// Function call
	g.DFS(2);
	cout << endl;
	cout << "Following is Breath First Traversal"
			" (starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}

// improved by Vishnudev C
