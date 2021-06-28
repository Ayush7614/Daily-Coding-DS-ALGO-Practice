// Floyd War Shall using C
// Author : Abhishek Sharma

#include<stdio.h>
#define V 4
#define INF 99999
void printSolution(int dist[][V]);
void floydWarshall (int graph[][V])
{
    int i,j,k;
    int dist[V][V];
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
                printf("%7s", "INF");
            else
                printf ("%d ", dist[i][j]);
        }
        printf("\n");
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
