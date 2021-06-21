#include<stdlib.h>
#include <stdio.h>
     
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void Sort();
void swap();
void Search();
void Reverse();
 
 
struct node
{
        int data;
        struct node *next;
};
struct node *start=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf("\n**********MENU**********");
                printf("\n 1.Create     ");
                printf("\n 2.Display    ");
                printf("\n 3.Insert at the beginning    ");
                printf("\n 4.Insert at the end  ");
                printf("\n 5.Insert at specified position       ");
                printf("\n 6.Delete from beginning      ");
                printf("\n 7.Delete from the end        ");
                printf("\n 8.Delete from specified position     ");
                printf("\n 9.Sort list");
                printf("\n 10.Reverse list");
                printf("\n 11.Search");
                printf("\n 12.Exit");
                printf("\n--------------------------------------");
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();           //create linkedlist  
                                        break;
                        case 2:
                                        display();          //display all elements of linkedlist
                                        break;
                        case 3: 
                                        insert_begin();     //insert at beginning
                                        break;
                        case 4:
                                        insert_end();       //insert element at end
                                        break;
                        case 5:
                                        insert_pos();       //insert element at certain location 
                                        break;
                        case 6:
                                        delete_begin();     //delete element from beginning 
                                        break;
                        case 7:
                                        delete_end();       //delete element for end
                                        break;
                        case 8:
                                        delete_pos();      //delete element fro a certain location       
                                        break;
                        case 9:
                                        Sort();           //sort elements in ascending(bubble sort)
                                        break;                
                        case 10:
                                        Reverse();       //Reverse linkedlist
                                        break;                
                        case 11:
                                        Search();       //for searching element in linkedlist
                                        break; 
                        case 12:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice\n");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space");
                exit(0);
        }
        printf("\nEnter the data value for the node: ");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}
void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are\n");
                while(ptr!=NULL)
                {
                        printf("%d ",ptr->data );
                        ptr=ptr->next ;
                }
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space\n");
                return;
        }
        printf("\nEnter the data value for the node: \t" );
        scanf("%d",&temp->data);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space");
                return;
        }
        printf("\nEnter the data value for the node: " );
        scanf("%d",&temp->data );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space");
                return;
        }
        printf("\nEnter the position for the new node to be inserted: ");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node: ");
        scanf("%d",&temp->data) ;
  
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { 
                    ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is Empty");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("\nThe deleted element is :%d ",ptr->data);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nList is Empty");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("\nThe deleted element is:%d",ptr->data);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\n The deleted element is:%d",ptr->data);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\n The List is Empty");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted: " );
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%d",ptr->data  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) {
                             temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d",ptr->data );
                        free(ptr);
                }
        }
}
void Sort()
{
    int i;
    struct node *P, *Q=NULL;
    if(start==NULL)
         printf ("\n List is Empty");

    do{
        i=0;
        P=start;
        while(P->next!=Q)
        {
            if(P->data>P->next->data)
            {
                swap(P,P->next);
                i=1;
            }
            P=P->next;
        }
        Q=P;
    }while(i);
    
}

void swap(struct node *S, struct node *T)
{
    int temp;
    temp=S->data;
    S->data=T->data;
    T->data=temp;
}

void Reverse ()
{
  struct node *P, *Q, *R;
  if (start == NULL)
    {
      printf ("\n List is Empty");
    }
  P = start;
  Q = R = NULL;
  while (P != NULL)
    {
      R = Q;
      Q = P;
      P = P->next;
      Q->next = R;
    }
  start = Q;
  
}

void Search()
{
    struct node *p;
    int flag=0,key,loc=0;
    printf("\n Enter the element to be searched:");
    scanf("%d",&key);
    for(p=start; p!=NULL; p=p->next)
    {
        loc=loc+1;
        if(p->data==key)
        {
            flag=1;
            
        }
    }
    
    if(flag==1)
   {printf("\n Element %d found at %d location",key,loc);
   }
    else
    {printf("\n Element not found in the list ");
    }
    
}
 