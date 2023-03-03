// C++ program to demonstrate some of the above
// terminologies
#include <bits/stdc++.h>
using namespace std;
// Function to add an edge between vertices x and y
void addEdge(int x, int y, vector<vector<int> >& adj)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}
// Function to print the parent of each node
void printParents(int node, vector<vector<int> >& adj,
				int parent)
{
	// current node is Root, thus, has no parent
	if (parent == 0)
		cout << node << "->Root" << endl;
	else
		cout << node << "->" << parent << endl;
	// Using DFS
	for (auto cur : adj[node])
		if (cur != parent)
			printParents(cur, adj, node);
}
// Function to print the children of each node
void printChildren(int Root, vector<vector<int> >& adj)
{
	// Queue for the BFS
	queue<int> q;
	// pushing the root
	q.push(Root);
	// visit array to keep track of nodes that have been
	// visited
	int vis[adj.size()] = { 0 };
	// BFS
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		vis[node] = 1;
		cout << node << "-> ";
		for (auto cur : adj[node])
			if (vis[cur] == 0) {
				cout << cur << " ";
				q.push(cur);
			}
		cout << endl;
	}
}
// Function to print the leaf nodes
void printLeafNodes(int Root, vector<vector<int> >& adj)
{
	// Leaf nodes have only one edge and are not the root
	for (int i = 1; i < adj.size(); i++)
		if (adj[i].size() == 1 && i != Root)
			cout << i << " ";
	cout << endl;
}
// Function to print the degrees of each node
void printDegrees(int Root, vector<vector<int> >& adj)
{
	for (int i = 1; i < adj.size(); i++) {
		cout << i << ": ";
		// Root has no parent, thus, its degree is equal to
		// the edges it is connected to
		if (i == Root)
			cout << adj[i].size() << endl;
		else
			cout << adj[i].size() - 1 << endl;
	}
}

// deletation of an edge between vertices x and y
void deleteEdge(int x, int y, vector<vector<int> >& adj)
{
	// find the index of y in adj[x]
	int index = -1;
	for (int i = 0; i < adj[x].size(); i++)
		if (adj[x][i] == y) {
			index = i;
			break;
		}
	// if y is not found, return
	if (index == -1)
		return;
	// remove y from adj[x]
	adj[x].erase(adj[x].begin() + index);
	// find the index of x in adj[y]
	index = -1;
	for (int i = 0; i < adj[y].size(); i++)
		if (adj[y][i] == x) {
			index = i;
			break;
		}
	// if x is not found, return
	if (index == -1)
		return;
	// remove x from adj[y]
	adj[y].erase(adj[y].begin() + index);
}

// insert an element into tree
// void insert(Node* root, int value)
// {
// 	if (root == NULL) {
// 		return;
// 	}
// 	if (root->data > value) {
// 		if (root->left == NULL) {
// 			root->left = new Node(value);
// 		} else {
// 			insert(root->left, value);
// 		}
// 	} else {
// 		if (root->right == NULL) {
// 			root->right = new Node(value);
// 		} else {
// 			insert(root->right, value);
// 		}
// 	}
// }

// function to height of a tree
// int height(int Root)
// {
// 	if (Root == NULL)
// 		return 0;
// 	return 1 + max(height(Root->left), height(Root->right));
// }

// Driver code
int main()
{
	// Number of nodes
	int N = 7, Root = 1;
	// Adjacency list to store the tree
	vector<vector<int> > adj(N + 1, vector<int>());
	// Creating the tree
	addEdge(1, 2, adj); // 1->2
	addEdge(1, 3, adj); // 1->3
	addEdge(1, 4, adj); // 1->4
	addEdge(2, 5, adj); // 2->5
	addEdge(2, 6, adj); // 2->6
	addEdge(4, 7, adj); // 4->7
	// Printing the parents of each node
	cout << "The parents of each node are:" << endl;
	printParents(Root, adj, 0);

	// Printing the children of each node
	cout << "The children of each node are:" << endl;
	printChildren(Root, adj);

	// Printing the leaf nodes in the tree
	cout << "The leaf nodes of the tree are:" << endl;
	printLeafNodes(Root, adj);

	// Printing the degrees of each node
	cout << "The degrees of each node are:" << endl;
	printDegrees(Root, adj);

	// cout << "Height: " << height(Root) << endl;
	// height(Root);

	return 0;
}
