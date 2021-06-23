// Find out the Subtraction of two given link list 125+85 =210 1->2->5 8->5
#include<stdio.h>
#include<math.h>
#include "linkedList.h"

void sub(struct node **list1,struct node **list2)
{
    struct node *p,*q;
    int c1=0,c2=0,temp;
    float sub1=0,sub2=0;
    p = (*list1);
    q = (*list2);
    while (p!=NULL)
    {
        sub1+=p->info *pow(10,c1);
        c1+=1;
        p = p->next;
    }
    while (q!=NULL)
    {
        sub2+=q->info *pow(10,c2);
        c2+=1;
        q = q->next;
    }
    if (sub1>sub2)
        temp = sub1-sub2;
    else
        temp = sub1-sub2;
    printf("%d",temp);
    linkedListFormation(temp);
}
void linkedListFormation(int temp)
{
    int n;
    struct node *P;
    P = NULL;
    while (temp!=0)
    {
        n = temp%10;
        temp = temp/10;
        InsBeg(&P,n);
    }
    printf("\nSubtraction Linked List : ");
    Traverse(&P);
}
void main()
{
    struct node *START1,*START2;
    START1=NULL;
    START2=NULL;
    InsBeg(&START1,1);
    InsBeg(&START1,2);
    InsBeg(&START1,5);
    InsBeg(&START2,8);
    InsBeg(&START2,5);
    printf("Subtraction of Lists :  ");
    sub(&START1,&START2);
}

