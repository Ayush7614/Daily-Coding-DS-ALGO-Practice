#include <bits/stdc++.h>
using namespace std;

bool flag = false;


map<int, int> dic;


bool cmp(int a, int b)
{
	
	return dic[a] < dic[b];
}

class Graph {
	int V; // No. of vertices
	int ctr; // ctr variable

public:
	list<int>* adj;

	Graph(int V); // Constructor

	
	void addEdge(int u, int v);

	void DFS(int v, int Perm[]);
};

Graph::Graph(int V)
{
	this->V = V;
	this->ctr = 0;
	adj = new list<int>[V + 1];
}

void Graph::addEdge(int u, int v)
{

	// Add v to u’s list.
	adj[u].push_back(v);

	// Add u to v's list
	adj[v].push_back(u);
}

void Graph::DFS(int v, int Perm[])
{
	
	ctr++;

	
	if (ctr == V) {

		// Set flag to 1
		flag = 1;
		return;
	}

	list<int>::iterator i;
	for (i = adj[v].begin();
		i != adj[v].end(); i++) {

		if (*i == Perm[ctr])
			DFS(*i, Perm);
	}
}
bool checkPermutation(
	int N, int M,
	vector<pair<int, int> > V,
	int P[])
{

	
	Graph G(N);

	// Add Edges to Graph G
	for (int i = 0; i < M; i++)
		G.addEdge(V[i].first,
				V[i].second);

	for (int i = 0; i < N; i++)
		dic[P[i]] = i;

	for (int i = 1; i <= N; i++)
		G.adj[i].sort(cmp);

	// Call DFS with source node as P[0]
	G.DFS(P[0], P);

	return flag;
}

// Input code
int main()
{
	
	int N,M;
	cin >> N;
	cin >> M;

	// Vector of pair to store edges
	vector<pair<int, int> > V;

	V.push_back(make_pair(1, 2));
	V.push_back(make_pair(2, 3));

	int P[N];
	for(int c=0;c<N;c++){
		cout << "number" << c << end1;
		cin >> P[c];
	}

	// Return the answer
	if (checkPermutation(N, M, V, P))
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}


/*
Example:
Input-
int N = 3, M = 2;
int P[] = { 1, 2, 3 };
Output-
True
*/
