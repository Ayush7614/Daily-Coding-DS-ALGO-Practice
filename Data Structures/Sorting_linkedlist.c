#include<stdlib.h>
#include<stdio.h>

void create ();
void display ();
void Sort ();
void swap();
struct node
{
  int data;
  struct node *next;
};
struct node *start = NULL;

int
main ()
{
  int choice;
  while (1)
    {
      printf ("\n**********MENU**********");
      printf ("\n 1. Create");
      printf ("\n 2. Display");
      printf ("\n 3. Sort");
      printf ("\n 4. Exit");

      printf ("\n Enter Your Choice: ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  create ();
	  break;

	case 2:
	  display ();
	  break;

	case 3:
	  Sort ();
	  break;

	case 4:
	  exit (0);
	  break;
	default:
	  printf ("\n Wrong Choice");

	}
    }
  return 0;
}

void
create ()
{
  struct node *temp, *ptr;
  temp = (struct node *) malloc (sizeof (struct node));

  if (temp == NULL)
    {
      printf ("\n Memory space not available");
      exit (0);
    }
  printf ("\n Enter the data value for node: ");
  scanf ("%d", &temp->data);
  temp->next = NULL;
  if (start == NULL)
    {
      start = temp;
    }
  else
    {
      ptr = start;
      while (ptr->next != NULL)
	{
	  ptr = ptr->next;
	}
      ptr->next = temp;
    }
}

void display ()
{
  struct node *ptr;

  if (start == NULL)
    {
      printf ("\n List is Empty");
    }
  else
    {
      ptr = start;
      printf ("\n The Elements are:  ");
      while (ptr != NULL)
	{
	  printf ("%d", ptr->data);
	  ptr = ptr->next;
	  printf("  ");
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