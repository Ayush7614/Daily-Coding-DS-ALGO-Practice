#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void main()
{
    struct node *start,*temp,*head,*prev,*cur,*nextnode;
    start=NULL;
    int i,c=1,item;
    printf("Enter data into the list\n");
    do
    {
        head=(struct node*)malloc(sizeof(struct node));
        printf("Enter number:");
        scanf("%d",&head->data);
        head->next=NULL;
        if(start==NULL)
        {
            start=head;
        }
        else
        {
            temp=start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=head;
        }
        printf("Do you wish to continue[1/0]:");
        scanf("%d",&c);
    }while(c!=0);
    printf("Displaying the nodes in the list:\n");
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\nReversing the list...\n");
    printf("Displaying the reversed list:\n");
    prev=NULL,nextnode=NULL,cur=start;
    while(cur!=NULL)
    {
        nextnode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextnode;
    }
    start=prev;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}