/*Transitive Closure of Graph
Input: N = 4
graph = {{1, 1, 0, 1},
{0, 1, 1, 0},
{0, 0, 1, 1},
{0, 0, 0, 1}}
Output: {{1, 1, 1, 1},
{0, 1, 1, 1},
{0, 0, 1, 1},
{0, 0, 0, 1}}
Explaination: The output list shows the
reachable indexes.
*/

//Code
#include<bits/stdc++.h>
using namespace std;
   
class Graph
{
    int V; 
    bool **tc; 
    list<int> *adj; 
    void DFSUtil(int u, int v);
public:
    Graph(int V);
   
    
    void addEdge(int v, int w) { adj[v].push_back(w); }
   
    
    void transitiveClosure();
};
   
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
   
    tc = new bool* [V];
    for (int i = 0; i < V; i++)
    {
        tc[i] = new bool[V];
        memset(tc[i], false, V*sizeof(bool));
    }
}
   

void Graph::DFSUtil(int s, int v)
{
   
     if(s==v){
        if(adjList[v].contains(v))
          tc[s][v] = true;
          }
      else
            tc[s][v] = true;
   
   
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (tc[s][*i] == false)
            DFSUtil(s, *i);
}
   

void Graph::transitiveClosure()
{
   
    for (int i = 0; i < V; i++)
        DFSUtil(i, i); 
   
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
            cout << tc[i][j] << " ";
        cout << endl;
    }
}
   

int main()
{
   
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);  
    cout << "Transitive closure matrix is \n";
    g.transitiveClosure();
    return 0;
}
