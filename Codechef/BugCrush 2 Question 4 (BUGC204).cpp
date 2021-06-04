#include<stdio.h>
#include<stdlib.h>
struct Node
{
int data;
struct Node* next;
};
int count(struct Node* head)
{
if (head == NULL)
return 0;
return 1+count(head->next);
}
void add(struct Node** header, int datum)
{
struct Node* point = (struct Node*) malloc(sizeof(struct Node));
point->data = datum;
point->next = (*header);
(*header) = point;
}
int main()
{
struct Node* head = NULL;
add(&head, 1);
add(&head, 3);
add(&head, 1);
add(&head, 2);
add(&head, 1);
printf("Count of nodes is %d", count(head));
return 0;
}