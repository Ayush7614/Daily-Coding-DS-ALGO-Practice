/*
TEST CASE 1:
               2---3
             /      \
        0---1---7--- 4---5---6
        INPUT:
            8 8
            0 1
            1 2
            1 7
            7 4
            2 3
            3 4
            4 5
            5 6
        OUTPUT:

            Graph is not a Bipartite Graph!

TEST CASE 2:
            2---3---4
            |       |
        0---1---8---5---6---7
        INPUT:
            9 9
            0 1
            1 8
            8 5
            5 6
            6 7
            1 2
            2 3
            3 4
            4 5

        OUTPUT:
            Graph is a Bipartite Graph!    

*/
#include <bits/stdc++.h>
#define vi vector
using namespace std;

void add_edge(vi<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool Bipartite_using_DFS(vi<int> adj[], vi<int> &color, int v, int start)
{
    vi<int>::iterator itr;
    for (itr = adj[start].begin(); itr != adj[start].end(); itr++)
    {
        if (color[*itr] == -1)
        {
            color[*itr] = 1 - color[start];
            if (!Bipartite_using_DFS(adj, color, v, *itr))
                return false;
        }
        else if (color[*itr] == color[start])
            return false;
    }
    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vi<int> adj[v];
    int src, dest;
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest;
        add_edge(adj, src, dest);
    }

    vi<int> color(v, -1);
    color[0] = 0;

    if (Bipartite_using_DFS(adj, color, v, 0))
    {
        cout << "Graph is a Bipartite Graph!" << endl;
    }
    else
    {
        cout << "Graph is not a Bipartite Graph!" << endl;
    }

    return 0;
}