#include <stdio.h>
#include "cLinkedList.h"
int josephusProblem(struct Node **CSTART,int k)
{
    struct Node *P,*Q;
    int count,x;
    P = (*CSTART)->next;
    printf("\nDeleted Nodes :\n");
    while (P->next!=P)
    {
        count = 1;
        while(count!=k-1)
        {
            count++;
            P = P->next;
        }
        Q = P;
        P = P->next;
        P = P->next;
        x = DelAft(Q);
        printf("%d\t",x);
    }
    return P->info;
 }


int main()
{
    struct Node *CSTART = NULL;
    int i,ans;
    for (i=1;i<101;i++)
    {
        InsEnd(&CSTART,i);
    }
    printf("Linked list :");
    Traversal(CSTART);
    ans = josephusProblem(&CSTART,12);
    printf("\nJosephus Problem = %d",ans);
    return 0;


}
