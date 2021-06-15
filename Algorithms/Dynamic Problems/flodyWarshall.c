// Floyd Warshall Algorithm
#include<stdio.h>

// Number of vertices in the graph
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
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++)
		{
			
			for (j = 0; j < V; j++)
			{
				
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// Print the shortest distance matrix
	printSolution(dist);
}

void printSolution(int dist[][V])
{
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				printf("%7s", "INF");
			else
				printf ("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int graph[V][V] = { {0, 5, INF, 10},
						{INF, 0, 3, INF},
						{INF, INF, 0, 1},
						{INF, INF, INF, 0}
					};

	// Print the solution
	floydWarshall(graph);
	return 0;
}


// Output -

/*
      0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0

*/

// INF is infinte 
// 0 means points are equal