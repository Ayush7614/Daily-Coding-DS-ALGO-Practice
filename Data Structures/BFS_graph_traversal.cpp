#include<iostream>
#include<stdlib.h>
using namespace std;
int cost[10][10],i,j,k,n,queue[10],front=0,rear=0,v,visit[10],visited[10]; 	//INITIALIZATION
int main()
{
	int m;
	cout <<"Enter no. of vertices: "; 	// TAKING INPUT VALUE FOR VERICES
	cin >> n;
	cout <<"Enter no. of edges: "; 		// TAKING INPUT VALUE FOR EDGES
	cin >> m;
	cout <<"\nEnter the EDGES: \n"; 
	for(k=1;k<=m;k++)
	{
		cin >>i>>j;						// GIVING THE EDGES VALUE (Eg:1 2)
		cost[i][j]=1; 
	}
	cout <<"\nEnter the initial vertex: "; 			// GIVING THE INITIAL VERTEX TO START
	cin >>v;										// BFS GRAPH TRAVERSAL
	cout <<"Visitied vertices (BFS) are: "; 
	cout <<v<<" ";
	visited[v]=1; 
	k=1; 
	while(k<n)										// MARKING THE NODES VISITED ONCE
	{
		for(j=1;j<=n;j++)
			if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1) 
			{
				visit[j]=1;
				queue[rear++]=j; 					// PUSHING THE NODE VISITED FIRST TIME
			}										// IN THE QUEUE
		v=queue[front++]; 
		cout<< v <<" "; 					// DISPLAYING THE BFS TRAVERSAL VALUES
		k++;
		visited[v]=1;
	}	
	cout<<"\n";
	return 0; 
}