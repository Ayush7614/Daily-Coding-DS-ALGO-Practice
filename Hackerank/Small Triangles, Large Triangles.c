#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/
    int *p=malloc(n*sizeof(int));
    triangle t; 
    for(int i=0;i<n;i++)
    {
    float a=(tr[i].a+tr[i].b+tr[i].c)/2.0;
       p[i]=(a*(a-tr[i].a)*(a-tr[i].b)*(a-tr[i].c));

    }
    for(int i=0;i<n;i++)    
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j]>p[j+1])     
            {
                int temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                t=tr[j];
                tr[j]=tr[j+1];
                tr[j+1]=t;

            }
        }
    }
}
