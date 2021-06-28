/* 
# Bellman Ford's Algorithm:
Bellman Ford algorithm helps us find the shortest path from a vertex(root) to all other vertices of a weighted 
graph. It can be implemented using DP. 


# lets discuss some of the benefits Of Bellman Ford Algorithm:
- It can calculate the shortest path in the graphs having negative weight edges whereas Dijkstra can't.
- A very important application of Bellman Ford is to check if there is a negative cycle in the graph.


Implementation:
*/

#include<bits/stdc++.h>
using namespace std;
const int NODES = 1e5;
const int MAX = 1e9;
const int EDGES = 2e5;

vector<int> v[EDGES];
int distance[NODES];
int main(){
for(int a = 0; a < NODES; a++){
    distance[a] = MAX;
}
for(int a = 0; a< EDGES; a++){
    v[a].clear();
}
int nodes, edges, start_node, end_node, dist;
cin >> nodes >> edges;
for(int a = 0; a < edges; a++){
    cin >> start_node >> end_node >> dist;
    v[a].push_back(start_node);
    v[a].push_back(end_node);
    v[a].push_back(dist);
}
distance[1] = 0; 
for(int a = 0; a < nodes-1; a++){
    int b = 0;
    while(v[b].size() != 0){
        if(distance[v[b][0]]+v[b][2]<distance[v[b][1]]){
            distance[v[b][1]] = distance[v[b][0]]+v[b][2];
        }
        b++;
    }
  /*
if ( assumed distance of  node a+distance between node a and another node b connected by an edge < assumed distance of node b)
{
    updated distance of b =  assumed distance of  node a + distance between node a and another node b  connected by an edge
}
It is similar to Dijkstra's algorithm but it can work with graphs with negative weights.
}
*/
for(int i = 1; i <= nodes; i++){
    cout<< dis[i] << "\n";
}
return 0;
}

/*
Test Case:
    Input:
        5 5
        1 2 5
        1 3 2
        3 4 1
        1 4 6
        3 5 5

    Output: 
        5 2 3 7




# Space Complexity:
It is O(v+e) and O(v^2) when using adjacency list and adjancency matrix respectively.


# Time Complexity:
It is O(e*(v-1)) where v and e represents no. of vertices and edges respectively.
- For completed graph:
no. of edges = v(v-1)/2
because in connected graph, each vertex is connected with every other node.
So. time complexity will be (v(v-1)/2)v which is equivalent to O(v^3)

- Worst Time Complexity: O(v^3).


*/
