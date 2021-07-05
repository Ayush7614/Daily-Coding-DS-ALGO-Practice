#include <iostream>
#include <stdlib.h>
using namespace std;
struct linked_list {
   int data;
   struct linked_list *next;
};
int stack[30], top = -1;
struct linked_list* head = NULL;
int printfromstack(int stack[]) {
   cout<<"\nStack after Reversal::";
   while(top>=0) {
      cout<<stack[top--]<<" ";
   }
}
int push(struct linked_list** head, int n) {
   struct linked_list* newnode = (struct linked_list*)malloc(sizeof(struct linked_list));
   newnode->data = n;
   newnode->next = (*head);
   (*head) = newnode;
}
int intostack(struct linked_list* head) {
   cout<<"Linked list::";
   while(head!=NULL) {
      printf("%d ", head->data);
      stack[++top] = head->data;
      head = head->next;
   }
}
int main(int argc, char const *argv[]) {
   push(&head, 7);
   push(&head, 20);
   push(&head, 3);
   push(&head, 40);
   intostack(head);
   printfromstack(stack);
   return 0;
}

/**Input **/
Linked list::40 3 20 7

/**Output **/
Stack after Reversal::7 20 3 40
