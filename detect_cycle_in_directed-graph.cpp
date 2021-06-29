/*Detect Cycle in a Directed Graph
Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.
Example, 
 

Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output: Yes

Solution using Depth First Search or DFS
 

Approach: Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree. There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is from a node to itself (self-loop) or one of its ancestors in the tree produced by DFS. In the following graph, there are 3 back edges, marked with a cross sign. We can observe that these 3 back edges indicate 3 cycles present in the graph.
 
 For a disconnected graph, Get the DFS forest as output. To detect cycle, check for a cycle in individual trees by checking back edges.
To detect a back edge, keep track of vertices currently in the recursion stack of function for DFS traversal. If a vertex is reached that is already in the recursion stack, then there is a cycle in the tree. The edge that connects the current vertex to the vertex in the recursion stack is a back edge. Use recStack[] array to keep track of vertices in the recursion stack.


Algorithm: 
Create the graph using the given number of edges and vertices.
Create a recursive function that initializes the current index or vertex, visited, and recursion stack.
Mark the current node as visited and also mark the index in recursion stack.
Find all the vertices which are not visited and are adjacent to the current node. Recursively call the function for those vertices, If the recursive function returns true, return true.
If the adjacent vertices are already marked in the recursion stack then return true.
Create a wrapper class, that calls the recursive function for all the vertices and if any function returns true return true. Else if for all vertices the function returns false return false.
*/

#include <iostream>
#include <vector>
using namespace std;

bool iscycle(int src, vector<vector<int>> &adj, vector<int> &stack, vector<int> &visited)
{
  stack[src] = 1;
  if (!visited[src])
    visited[src] = 1;
  for (auto x : adj[src])
  {
    if (!visited[x] and iscycle(x, adj, stack, visited))
    {
      return true;
    }
    if (stack[x])
      return true;
  }
  stack[src] = 0;
  return false;
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  vector<int> visited(n, 0);
  bool cycle = false;
  vector<int> stack(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] and iscycle(i, adj, stack, visited))
    {
      cycle = true;
    }
  }
  if (cycle)
    cout << "cycle ";
  else
    cout << "not a cycle";

  return 0;
}


/*
Input:n = 4, e = 4
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 3
Output:Cycle 

Input: n = 4, e = 6
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3
Output:not a cycle

*/