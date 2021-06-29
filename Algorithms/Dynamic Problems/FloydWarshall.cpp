// Floyd War Shall problem using C++

// Author : Abhishek Sharma

#include <bits/stdc++.h>
using namespace std;
#define V 4
#define INF 99999
void printSolution(int dist[][V]);
void floydWarshall (int graph[][V])
{
    int dist[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}

void printSolution(int dist[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<"     ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int graph[V][V] = { {0, 11, 1, 6},
                        {11, 0, 7, 3},
                        {1, 7, 0, 2},
                        {6, 3, 2, 0}
                    };
    floydWarshall(graph);
    return 0;
}



// Test Cases
// Input
0 11 1 6
11 0 7 3
1 7 0 2
6 3 2 0

// Output
0 6 1 3
6 0 5 3
1 5 0 2
3 3 2 0
