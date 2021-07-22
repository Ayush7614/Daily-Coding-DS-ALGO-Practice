#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct stack
{
    int data[100000];
    int top;
}S;

int max=0;

void push()
{
    int item;
    scanf("%d",&item);
    S.top++;
    S.data[S.top]=item;
    if(max<S.data[S.top])
        max=S.data[S.top];
   
}
void pop()
{
    int i;
    if(max == S.data[S.top])
        max=0;
    S.top--;
     for(i=S.top;i>=0;i--)
        if(max<S.data[i])
            max=S.data[i];
}

int main()
{
    int t,n,choice;
    S.top = -1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :push();
            break;
            case 2:pop();
            break;
            case 3: printf("%d\n",max);
            break;
        }
    }
    return 0;
}
