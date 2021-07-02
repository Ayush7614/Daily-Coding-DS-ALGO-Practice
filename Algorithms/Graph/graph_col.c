#include<stdio.h>

void nextvalue(int x[50],int g[50][50],int k,int n,int m)
{
	int j;
 	while(1)
 	{
   		x[k] = (x[k]+1) % (m+1);    			//next higher color
   		if(x[k] == 0)             				//all colors have been used
      		return;

      	//checking if this color is distinct from adjacent colors	
   		for(j=1; j<=n; j++)         
   		{                          
     		if(g[k][j] != 0 && (x[k] == x[j]))	//if (k,j) is an edge and if adjacent vertices have the same color
        		break; 
   		}
     	if(j == n+1)           //new color found       
       		return;                    
  	}
}

void mcoloring(int x[50],int g[50][50],int k,int n,int m)
{
	int i;
  	do								//loop for generating all legal assignments for x[k]
 	{                         
   		nextvalue(x, g, k,n ,m);    //Assign to x[k] a legal color

   		if(x[k] == 0)             	//No new color possible
     		return; 

		if(k == n)                //Atmost m colors have been used to color the n vertices
   		{
    		for(i=1 ;i<=n; i++)
      		    printf("V %d : %d \t",i,x[i]);
      		printf("\n");
   		}
  		else
		mcoloring(x, g, k+1, n, m); 

 	}while(k<n+1); 
}

//Main function
int main()
{
	int n,ne,u,v,i,j,x[50],g[50][50],m;

	printf("\n no of ver");
	scanf("%d",&n);				

	printf("\n no of edges");
	scanf("%d",&ne);			

  	m = n-1;
  	printf("\n maximum possible colors %d \n",m);

  	//The graph is represented by its boolean adjacency matrix G[1:n,1:n]
  	for(i=0; i<=n; i++)
    	for(j=0; j<=n; j++)
       		g[i][j] = 0;

  	for(i=1; i<=ne; i++)
	{
	 	printf("\n first terminal vertex of edge %d",i);
	 	scanf("%d",&u);

	 	printf("\n second terminal vertex of edge %d",i);
	 	scanf("%d",&v);

		g[u][v] = 1;
   		g[v][u] = 1;
  	}

   	for(i=0; i<=n; i++)
      	x[i] = 0;

	printf("\n one of the coloring pattern is \n");
    mcoloring(x ,g ,1 ,n ,m);
}

/*
Input-
no of ver: 4
no of edges: 4
maximum possible colours 3
first terminal vertex of edge 1: 1
second terminal vertex of edge 1: 2
first terminal vertex of edge 2: 2
second terminal vertex of edge 2: 3
first terminal vertex of edge 3: 3
second terminal vertex of edge 3: 4
first terminal vertex of edge 4: 1
second terminal vertex of edge 4: 4
one of the coloring pattern is:
V1: 1   V2: 2   V3: 1   V4: 2
V1: 1   V2: 2   V3: 1   V4: 3
V1: 1   V2: 2   V3: 3   V4: 2
V1: 1   V2: 3   V3: 1   V4: 2
V1: 1   V2: 3   V3: 1   V4: 3
V1: 1   V2: 3   V3: 2   V4: 3
V1: 2   V2: 1   V3: 2   V4: 1
V1: 2   V2: 1   V3: 2   V4: 3
V1: 2   V2: 1   V3: 3   V4: 1
V1: 2   V2: 3   V3: 1   V4: 3
V1: 2   V2: 3   V3: 2   V4: 1
V1: 2   V2: 3   V3: 2   V4: 3
V1: 3   V2: 1   V3: 2   V4: 1
V1: 3   V2: 1   V3: 3   V4: 1
V1: 3   V2: 1   V3: 3   V4: 2
V1: 3   V2: 2   V3: 1   V4: 2
V1: 3   V2: 2   V3: 3   V4: 1
V1: 3   V2: 2   V3: 3   V4: 2
*/
