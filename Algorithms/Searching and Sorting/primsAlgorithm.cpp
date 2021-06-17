// C program for implementation of
// Prim's algorithm
// Time Complexity : O(ElogV)

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
// setting no. of vertices
#define V 5
// 2-D array for adjacency matrix
int G[V][V]={
	{0, 9, 75, 0, 0},
  	{9, 0, 95, 19, 42},
  	{75, 95, 0, 51, 66},
  	{0, 19, 51, 0, 31},
  	{0, 42, 66, 31, 0}
};
// driver code
int main()
{
	int n;
	int selected[V];
	// set selected false initially
	memset(selected, false, sizeof(selected));
	n=0;
	selected[0]=true;
	int row;
	int col;
	printf("Edge : weight\n");
	while(n<V-1)
	{
		int min=9999999;
		row=0;
		col=0;
		for(int i=0;i<V;i++)
		{
			if(selected[i])
			{
				for(int j=0;j<V;j++)
				{
					if (!selected[j] && G[i][j])
					{
						if (min > G[i][j])
						{
							min = G[i][j];
              				row = i;
              				col = j;
						}
					}
				}
			}
		}
	printf("%d - %d : %d\n",row,col,G[row][col]);
    selected[col] = true;
    n++;
	}
	return 0;
}

