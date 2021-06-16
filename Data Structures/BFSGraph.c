#include<stdio.h>

#include<conio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;      //Variable Initialization

void bfs(int v) {

for(i = 1; i <= n; i++)

if(a[v][i] && !visited[i])

q[++r] = i;

if(f <= r) {

visited[q[f]] = 1;

bfs(q[f++]);

}

}

//Driver Code

void main() {

int v;

printf("Enter the number of vertices: ");

scanf("%d",&n);

for(i=1; i <= n; i++) {

q[i] = 0;

visited[i] = 0;

}

printf("\nEnter graph data in matrix form:\n");

for(i=1; i<=n; i++) {

for(j=1;j<=n;j++) {

scanf("%d", &a[i][j]);

}

}

printf("Enter the starting vertex: ");

scanf("%d", &v);

bfs(v);

printf("\nThe node which are reachable are:");

for(i=1; i <= n; i++) {

if(visited[i])

printf(" %d", i);

else {

printf("\nBFS is not possible. All nodes are not reachable!");

break;

}

}

getch();

}