//Kahn’s Algorithm for Topological Sort
//Kahn’s algorithm in order to form topological order constantly looks for the vertices that have no incoming edge and removes all outgoing edges from them.

//Basically, the algorithm:

//1.Finds the vertex that has no incoming edges.
//2.Remove all outgoing edges from that vertex.
//3.Add vertex to the topological order.
//4.Repeat the process until all the vertices are processed.

#include <bits/stdc++.h>
using namespace std;

vector <int> topoSort(vector<int>adj[],int n,vector <int> indegree){
  queue<int> q;
  vector <int> topo;
  for (int i = 0; i < n; i++)
    if (indegree[i] == 0) q.push(i);

  while(q.size()>0){
    int node = q.front();
    q.pop();
    topo.push_back(node);
    for(auto it:adj[node]){
      indegree[it]--;
      if(indegree[it]==0){
        q.push(it);
      }
    }
  }
  return topo;
}

int main(){
  int n,m;
  cin>>n>>m;
  vector <int> adj[n];
  vector <int> indegree(n,0);
  int a,b;
	for(int i = 0; i<m ; i++){
		cin >> a >> b;
		adj[a].push_back(b);
    indegree[b]++;
	}	
  vector <int> res = topoSort(adj,n,indegree);
  for(int i{0};i<res.size();i++){
    cout<<res[i]<<" ";
  }
  return 0;
}
