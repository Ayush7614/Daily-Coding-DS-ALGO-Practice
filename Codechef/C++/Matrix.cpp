/*Ronak’s class teacher gives him an NxN matrix.
Then, she gives him M numbers. Every number is an angle, the angle by which he has to rotate the matrix in clockwise direction. (The angles are multiples of 90.)
Help him with the task.
Input
First line consists of two numbers N and M.
The following N lines contain N numbers each (representing the matrix).
The next M lines contain one number each, representing the angle by which the matrix is to be rotated.
Output
For M problems, generate M appropriately rotated matrices, each separated by a new line.
Constraints
1 ≤ N,M ≤ 100
Example
Input:
4 2
1 2 3 4
4 5 6 7
6 8 4 3
8 1 4 7
90
180

Output:
8 6 4 1
1 8 5 2
4 4 6 3
7 3 7 4

7 4 1 8
3 4 8 6
7 6 5 4
4 3 2 1 
/*

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,k,n,m,angle,**arr,**arr1;
    scanf("%d %d",&n,&m);
    arr=(int**)malloc(sizeof(int*)*n);
    arr1=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
        arr[i]=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        arr1[i]=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
            arr1[i][j]=arr[i][j];
        }

    for(k=0;k<m;k++)
    {
        scanf("%d",&angle);
        if((angle/90)%4==0)
        {
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n;j++)
                    {
                        printf("%d ",arr[i][j]);
                    }
                    printf("\n");
                }

        }
        else if((angle/90)%4==1)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    arr1[i][j]=arr[n-1-j][i];
                    printf("%d ",arr1[i][j]);
                }
                printf("\n");
            }

        }
        else if((angle/90)%4==2)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    arr1[i][j]=arr[n-1-i][n-1-j];
                    printf("%d ",arr1[i][j]);
                }
                printf("\n");
            }

        }

        else
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    arr1[i][j]=arr[j][n-1-i];
                    printf("%d ",arr1[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
