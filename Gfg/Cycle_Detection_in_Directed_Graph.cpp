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