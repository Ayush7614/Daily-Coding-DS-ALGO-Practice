/*
Push Element=12
Push Element=25
Push Element=36
Push Element=47
Push Element=58

Display: 58  47  36  25  12

pop() : popped element=58
pop() : popped element=47
pop() : popped element=36
*/
#include <bits/stdc++.h>
using namespace std;

//ARRAY IMPLEMENTATION//
#define MAX 5
int top = -1, stack_arr[MAX];

void arr_push()
{
    if (top == MAX - 1)
    {
        cout << "stack_arr is Full\n";
        return;
    }
    else
    {
        int data;
        top++;
        cout << "Enter the Data to be Pushed: ";
        cin >> data;
        stack_arr[top] = data;
    }
}

void arr_pop()
{
    if (top == -1)
    {
        cout << "stack_arr is Empty.\n";
        return;
    }
    else
    {
        cout << "Pop Element: " << stack_arr[top] << "\n";
        top--;
    }
}

void arr_top_element()
{
    cout << "Top Element: " << stack_arr[top] << "\n";
}

void arr_display()
{
    if (top == -1)
    {
        cout << "stack_arr is Empty.\n";
        return;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stack_arr[i] << "\t";
        }
        cout << "\n";
    }
}

void arr_implementation()
{
    int n;
    do
    {
        cout << "********ARRAYY IMPLEMENTATION*******\n";
        cout << "1. Push Data into stack\n";
        cout << "2. Pop Data from stack\n";
        cout << "3. Top Element of stack\n";
        cout << "4. Display the Element of stack\n";
        cout << "5. Exit.\n";
        cout << "Enter any one of the above option: ";
        cin >> n;
        switch (n)
        {
        case 1:
            arr_push();
            break;
        case 2:
            arr_pop();
            break;
        case 3:
            arr_top_element();
            break;
        case 4:
            arr_display();
            break;
        case 5:
            return;
            break;
        }
    } while (n < 6);
}

//LINKED LIST IMPLEMENTATION//
struct node
{
    int data;
    node *next;
} * head;

void ll_push()
{
    int data;
    cout << "Enter the Data to be Pushed: ";
    cin >> data;
    node *newnode = new node();
    newnode->data = data;
    if (head == NULL)
    {
        newnode->next = NULL;
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void ll_pop()
{
    if (head == NULL)
    {
        cout << "Stack is Empty.\n";
    }
    else
    {
        node *ptr = head;
        cout << "Pop Element: " << ptr->data << "\n";
        head = ptr->next;
        free(ptr);
    }
}

void ll_top()
{
    if (head == NULL)
    {
        cout << "Stack is Empty.\n";
    }
    else
    {
        cout << "Top Element: " << head->data << "\n";
    }
}

void ll_display()
{
    if (head == NULL)
    {
        cout << "Stack is Empty.\n";
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "\n";
    }
}

void ll_implementation()
{
    int n;
    do
    {
        cout << "******LINKED LIST IMPLEMENTATION*******\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter any one of the above option: ";
        cin >> n;
        switch (n)
        {
        case 1:
            ll_push();
            break;
        case 2:
            ll_pop();
            break;
        case 3:
            ll_top();
            break;
        case 4:
            ll_display();
            break;
        case 5:
            return;
            break;
        }
    } while (n < 6);
}

//DRIVER FUNCTION//
int main()
{
    int n;
    do
    {
        cout << "************MAIN MENU************\n";
        cout << "1. Array Implementation.\n";
        cout << "2. Linked List Implementation.\n";
        cout << "3. Exit.\n";
        cout << "Enter any one of the above option: ";
        cin >> n;
        switch (n)
        {
        case 1:
            arr_implementation();
            break;
        case 2:
            ll_implementation();
            break;
        case 3:
            return 0;
            break;
        }
    } while (n < 4);
}
