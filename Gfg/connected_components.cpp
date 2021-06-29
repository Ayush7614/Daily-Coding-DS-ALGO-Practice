#include <iostream>
#include <vector>
using namespace std;

int get_component(int u, vector<int> &visited, vector<vector<int>> &adj)
{
  if (visited[u])
    return 0;
  int ans = 1;

  visited[u] = 1;
  for (auto x : adj[u])
  {
    if (!visited[x])
      ans += get_component(x, visited, adj);
    visited[x] = 1;
  }

  return ans;
}
int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<int> visited(n, 0);
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> components;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      components.push_back(get_component(i, visited, adj));
    }
    
  }
  for (auto i : components)
      cout << i << endl;
  
}
