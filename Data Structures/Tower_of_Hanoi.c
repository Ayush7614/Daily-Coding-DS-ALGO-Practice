//recursive function for tower of Hanoi problem.
#include<stdio.h>
#include<conio.h>
void TOH(int,char,char,char);
void main()
{
 int n;
 printf("\nEnter number of disc ");
 scanf("%d",&n);
 TOH(n,'A','B','C');
 getch();
}
void TOH(int n,char beg, char aux, char end)
{
 if(n>0)
 {
 TOH(n-1,beg,end,aux);
 printf("\nMove Disc from %c to %c",beg,end);
 TOH(n-1,aux,beg,end);
 }
}
