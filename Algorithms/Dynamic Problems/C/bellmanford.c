/*
CODE DESCRIPTION:
The programs implements the bellman ford algorithm which finds shortest paths from source to all vertices in the given weighted graph.
The graph may contain negative weight edges too.
It works by overestimating the length of the path from the starting vertex to all other vertices by setting it as Infinite at first.
Then it iteratively relaxes those estimates by finding new paths that are shorter than the previously overestimated paths.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* Defining a Structure for the weighted edges of the graph */
struct Edge
{  
    int source, destination, weight;
};
 
/* Defining a Structure for Graph */
struct Graph
{
    int V, E;	
    struct Edge* edge;
};

/* Function to create a Graph with V:Vertices and E:Edges */
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph));
	graph->V = V;   
    graph->E = E;
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
	return graph;
}

/* Function to print the final distance Array */
void FinalSolution(int dist[], int n)
{
    int i;
    for (i = 0; i < n; ++i){
    printf("%d   --->   %d\n", i, dist[i]);
  }
}

/* Function for the implementation of Bellman Ford Algorithm */
void BellmanFord(struct Graph* graph, int source)
{
	/* V and E are for storing the total vertices and edges in graph respectively */
    int V = graph->V;
    int E = graph->E;
    /* Store Distance Array is to store the distance between paths */
    int StoreDistance[V];
    int i,j;
    /* Updating the distance from source to all other vertices as Infinite which is INT_MAX */
    for (i = 0; i < V; i++)
        StoreDistance[i] = INT_MAX;
	/* Marking the source vertex */ 
    StoreDistance[source] = 0;

	/* Relax all edges |V| - 1 times and store the edge data */
    for (i = 1; i <= V-1; i++)
    {
        for (j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (StoreDistance[u] + weight < StoreDistance[v])
                StoreDistance[v] = StoreDistance[u] + weight;
        }
    }
	/* Detects a negative cycle in graph */
    for (i = 0; i <E; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (StoreDistance[u] + weight < StoreDistance[v])
        {
            printf("This graph contains negative edge cycle\n");
            return; 
    	}	
    }
    FinalSolution(StoreDistance, V);
    return;
}
 
 /* Driver Function */
int main()
{
	//Here S : Source vertex , V : Vertex and  E : Edge
    int S,V,E;  
 
  	printf("Enter number of vertices : ");
    scanf("%d",&V);
 
  	printf("Enter number of edges : ");
    scanf("%d",&E);
 
  	printf("Enter your source number : ");
  	scanf("%d",&S);
 
    struct Graph* graph = createGraph(V, E);    

    int i;
    for(i=0;i<E;i++){
        printf("\nEnter edge %d properties : \n",i+1);
        printf("Source : ");
        scanf("%d",&graph->edge[i].source);
        printf("Desination : ");
        scanf("%d",&graph->edge[i].destination);
        printf("Weight : ");
        scanf("%d",&graph->edge[i].weight);
        printf("\n");
    }
  	printf("Distance Array is : \n");
    BellmanFord(graph, S);  
 
    return 0;
}
/*
Complexity:
Time Complexity : O(VE)
Space Complexity : O(V)
OUTPUT:
Enter number of vertices : 5
Enter number of edges : 8
Enter your source number : 0

Enter edge 1 properties :
Source : 0
Desination : 1
Weight : -1


Enter edge 2 properties :
Source : 0
Desination : 2
Weight : 4


Enter edge 3 properties :
Source : 1
Desination : 2
Weight : 3


Enter edge 4 properties :
Source : 1
Desination : 3
Weight : 2


Enter edge 5 properties :
Source : 1
Desination : 4
Weight : 2


Enter edge 6 properties :
Source : 3
Desination : 2
Weight : 5


Enter edge 7 properties :
Source : 3
Desination : 1
Weight : 1


Enter edge 8 properties :
Source : 4
Desination : 3
Weight : -3

Distance Array is : 
0   --->   0
1   --->   -1
2   --->   2
3   --->   -2
4   --->   1
*/
