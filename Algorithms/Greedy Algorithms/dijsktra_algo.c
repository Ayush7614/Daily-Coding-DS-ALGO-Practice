/*
CODE DESCRIPTION:
Following is a program to implement Dijkstra's Algorithm which is  an algorithm for finding the shortest paths from source to all vertices in the given graph.
It is also called single source shortest path algorithm.
*/
#include<stdio.h>
#include<conio.h>
#define V 5  
#define INFINITY 99
/* Program has predefined number of vertices as 5 and Infinity as 99 */
/* Method  to find the vertex with minimum distance */
int min_Dist(int dist[], int visited[])   
{
	int min=INFINITY,index;   
	int v;              
	for(v=1;v<=V;v++)
	{	/* If vertex is not yet visited */
		if(visited[v]==0 && dist[v]<=min)      
		{
			min=dist[v];
			index=v;
		}
	}
	return index;
}
/* Method to implement Dijsktra -Shortest path algorithm */
void Dijkstra(int cost[V][V],int src) 
{
	int dist[V];                             
	int visited[V];
	int i;
	//Initialize dist[] and visited[] : Visited is set to 0 if not visited and 1 if visited
	for(i=1;i<=V;i++)                    
	{
		dist[i]=INFINITY;
		visited[i]=0;	
	}
	//Initialize distance of the source vertex to zero
	dist[src]=0;        
	int c;                           
	for(c=2;c<=V;c++)                           
	{
		/* u is the vertex that is not yet visited and is having minimum distance */
		int u=min_Dist(dist,visited);       
		visited[u]=1;   
		int v;                       
		for(v=1;v<=V;v++)                    
		/* Update dist[v] for vertex v which is not yet visited and there exits a path from src to v through u that has smaller distance than current value of dist[v] */
		{
			if(!visited[v] && cost[u][v] && dist[u]+cost[u][v]<dist[v])
			dist[v]=dist[u]+cost[u][v];
		}
	}
	 /* Prints distances from the source */
	printf("The shortest path  %d to all the other vertices is: \n",src);
	for(i=1;i<=V;i++)                      
	{
	   if(i!=src)
	   printf("source: %d \t destination: %d \t MinCost is: %d \n",src,i,dist[i]);
	}
}
int main()
{
	int cost[V][V], i,j, s;
	printf("Enter the cost matrix ");
	for(i=1;i<=V;i++)  
	{   
    	for(j=1;j<=V;j++)
          	{
			scanf("%d",&cost[i][j]);
			/* If no edge present- Store Infinity */
             if(cost[i][j]==0)     
               cost[i][j]=INFINITY;    
           	}
    }
	printf("Enter the Source Vertex"); 
	scanf("%d",&s);

	Dijkstra(cost,s);
	return 0;	
}
/*
COMPLEXITY :
Time complexity : O(V^2)
OUTPUT:
Enter the cost matrix 1
2
2
2
3
4
4
7
99
8
99
6
5
8
99
3
99
99
99
99
2
3
4
5
Enter the Source Vertex1
The shortest path  1 to all the other vertices is:
source: 1        destination: 2          MinCost is: 2
source: 1        destination: 3          MinCost is: 2
source: 1        destination: 4          MinCost is: 2
source: 1        destination: 5          MinCost is: 3
*/
