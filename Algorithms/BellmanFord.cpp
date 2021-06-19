/*Bellman Ford algorithm overcomes the problem of negative weights that is there in Dijkstra's algorithm
Bellman Ford algorithm works by overestimating the length of the path from the starting vertex to all other vertices. Then it iteratively relaxes those estimates by finding new paths that are shorter than the previously overestimated paths.
By doing this repeatedly for all vertices, we can guarantee that the result is optimized.

Drawback: Can't be used in the graphs where a negative cycle exists.*/

/*Algorithm:
1. Start with a weighted graph.
2. Choose a source that is the starting vertex, assign 0 to its shortest distance as the shortest distance of the source to itself will always be zero.
3. Assign infinity initially to all the other vertices' distance.
4. Visit each edge and relax the path distances if they are inaccurate.
5. We need to do this |V| times because in the worst case a vertex's path length might need to be readjusted |V| times.
*/
#include <bits/stdc++.h>
using namespace std;


vector<int> BellmanFord(vector<vector<int>> edges, int n, int src){
    vector<int> dist(n, INT_MAX);
    dist[src]=0;

    //Repeat |V| times
    for(int i=0; i<n-1; i++){
        bool any_edge_updated=false;

        for(auto edge: edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            //Relaxation
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
                any_edge_updated=true;
            }
        }
        //If not even a single edge's path length is changed in an iteration, that means now the paths for any vertex can't be optimised further. So we can break out of the loop.
        if(!any_edge_updated) break;
    }
    return dist;
}


int main(){
    vector<vector<int>> edges{ { 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 }, { 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 } };
    int n=5;
    vector<int> dist=BellmanFord(edges, n, 0);
    for(int i=0; i<n; i++){
        cout<<i<<"->"<<dist[i]<<endl;
    }
    return 0;

}