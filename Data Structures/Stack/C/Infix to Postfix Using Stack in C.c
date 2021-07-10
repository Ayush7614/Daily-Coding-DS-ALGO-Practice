#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define SIZE 100

int top = -1;
char stack[SIZE];

void push(char item)
{
    if(top >= SIZE-1)
    {
        printf("\nStack Overflow.");
    }
    else
    {
        top = top+1;
        stack[top] = item;
    }
}

char pop()
{
    char item ;

    if(top <0)
    {
        printf("\nStack Underflow!");
        exit(1);
    }
    else
    {
        item = stack[top];
        top = top-1;
        return(item);
    }
}

int is_operator(char op)
{
    if(op == '^' || op == '*' ||  op == '/' || op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_precedence(char op)
{
    if(op == '^')
    {
        return 3;
    }
    else if(op == '*' || op == '/')
    {
        return 2;
    }
    else if(op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    char el, item;
    int i = 0, j = 0;
    push('(');
    strcat(infix, ")");
    item = infix[i];
    while(item != '\0')
    {
        if(item == '(')
        {
            push(item);
        }
        else if(isdigit(item) || isalpha(item))
        {
            postfix[j] = item;
            j++;
        }
        else if(is_operator(item) == 1)
        {
            el = pop();
            while(is_operator(el) == 1 && check_precedence(el) >= check_precedence(item))
            {
                postfix[j] = el;
                j++;
                el = pop();
            }
            push(el);
            push(item);
        }
        else if(item == ')')
        {
            el = pop();
            while(el != '(')
            {
                postfix[j] = el;
                j++;
                el = pop();
            }
        }
        else
        {
            printf("\nInvalid expression!");
            exit(1);
        }
        i++;
        item = infix[i];
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[SIZE], postfix[SIZE];
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("%s", postfix);
    return 0;
}