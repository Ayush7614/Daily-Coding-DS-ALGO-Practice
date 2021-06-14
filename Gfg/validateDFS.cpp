// C++ program to check if given
// permutation can be obtained
// upon DFS traversal on given graph

#include <bits/stdc++.h>
using namespace std;

// To track of DFS is valid or not.
bool flag = false;

// HashMap to store the indexes
// of given permutation

map<int, int> mp;

// Comparator function for sort
bool cmp(int a, int b)
{
	// Sort according ascending
	// order of indexes
	return mp[a] < mp[b];
}

// Graph class represents an undirected
// using adjacency list representation

class Graph {
	int V; // No. of vertices
	int counter; // Counter variable

public:
	// Pointer to an array containing
	// adjacency lists
	list<int>* adj;

	Graph(int V); // Constructor

	// function to add an edge to graph
	void addEdge(int u, int v);

	// DFS traversal of the vertices
	// reachable from v
	void DFS(int v, int Perm[]);
};

Graph::Graph(int V)
{
	this->V = V;
	this->counter = 0;
	adj = new list<int>[V + 1];
}

void Graph::addEdge(int u, int v)
{

	// Add v to u’s list.
	adj[u].push_back(v);

	// Add u to v's list
	adj[v].push_back(u);
}

// DFS traversal of the
// vertices reachable from v.

void Graph::DFS(int v, int Perm[])
{
	// Increment counter for
	// every node being traversed
	counter++;

	// Check if counter has
	// reached number of vertices
	if (counter == V) {

		// Set flag to 1
		flag = 1;
		return;
	}

	// Recur for all vertices adjacent
	// to this vertices only if it
	// lies in the given permutation

	list<int>::iterator i;
	for (i = adj[v].begin();
		i != adj[v].end(); i++) {

		// if the current node equals to
		// current element of permutation
		if (*i == Perm[counter])
			DFS(*i, Perm);
	}
}

// Returns true if P[] is a valid DFS of given
// graph. In other words P[] can be obtained by
// doing a DFS of the graph.

bool checkPermutation(
	int N, int M,
	vector<pair<int, int> > V,
	int P[])
{

	// Create the required graph with
	// N vertices and M edges
	Graph G(N);

	// Add Edges to Graph G
	for (int i = 0; i < M; i++)
		G.addEdge(V[i].first,
				V[i].second);

	for (int i = 0; i < N; i++)
		mp[P[i]] = i;

	// Sort every adjacency
	// list according to HashMap
	for (int i = 1; i <= N; i++)
		G.adj[i].sort(cmp);

	// Call DFS with source node as P[0]
	G.DFS(P[0], P);

	// If Flag has been set to 1, means
	// given permutation is obtained
	// by DFS on given graph
	return flag;
}

// Driver code

int main()
{
	// Number of vertices
	// and number of edges
	int N = 3, M = 2;

	// Vector of pair to store edges
	vector<pair<int, int> > V;

	V.push_back(make_pair(1, 2));
	V.push_back(make_pair(2, 3));

	int P[] = { 1, 2, 3 };

	// Return the answer
	if (checkPermutation(N, M, V, P))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
