#include<stdio.h>
#include<conio.h>
#define MAX50
int stack [MAX + 1], top=0;

// MAIN Function

void main()
{
  clrscr();
  void create(), traverse(), push(), pop();
      
  create();                         // Calling Create function
  printf("\n stack is: \n");
  traverse();
  
  push();                                 // Calling PUSH function to enter elements
  printf("After Push the element in the stack is: \n");
  traverse();
  
  pop();                                    // Calling POP function to delete elements
  printf("After pop the element in the stack is: \n");
  traverse();                                           // Calling traverse function
  
  getch();
}

// Function to create stack

void create()
{
   char ch;
  do
  {
    top++;
    printf("Input Element");
    scanf("%d", stack[top]);
    printf("Press <Y> for more element \n");
    ch=getch();
  }
  while(ch=='Y')
  }

// Function to traverse stack

void traverse()
{
  int i;
  for(i=top; i>0; --i)
    printf("%d\n",stack[i]);
}

// Function to enter elements in stack

void push()
{
  int m;
  if(top==MAX)
  {
    printf("Stack is overflow");
    return;
  }
printf("Input new element to insert");
  scanf("%d",&m);
  top++;
  stack[top]=m;
}

// Function to delete elements from stack

void pop()
{
  if(top==0)
  {
    printf("Stack is underflow\n");
    return;
  }
  stack[top]='\0';
  top--;
}
