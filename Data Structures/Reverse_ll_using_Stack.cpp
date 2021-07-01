/*
    ******MAIN MENU********
    1. Create a Linked List.
    2. Display Linked List.
    3. Reverse a Linked List.
    4. Exit.

TEST CASE:
    1. Create a Linked List.
        Enter the number of nodes in linked list: 5
        Enter the data of node 1: 14
        Enter the data of node 2: 25
        Enter the data of node 3: 36
        Enter the data of node 4: 47
        Enter the data of node 5: 58
    2. Display Linked List.
        Linked List:     14--> 25--> 36--> 47--> 58--> NULL
    3. Reverse a Linked List.
        Linked List Reversed Succesfully
    2. Display Linked List.
        Linked List:     58--> 47--> 36--> 25--> 14--> NULL
*/

#include <bits/stdc++.h>
using namespace std;

//******REVERSE A LINKED LIST*******//

struct node
{
    int data;
    node *next;
} * top1, *top2;

//Function For Pushing Element into Stack//

void push_ll(int data2)
{
    node *temp = new node();
    temp->data = data2;
    if (top2 == NULL)
    {
        temp->next = NULL;
        top2 = temp;
    }
    else
    {
        temp->next = top2;
        top2 = temp;
    }
}

//Function For Popping Element from Stack//

int pop_ll()
{
    node *ptr = top2;
    int num = ptr->data;
    top2 = ptr->next;
    free(ptr);
    return num;
}

//Function for Displaying Linked List//

void Display()
{
    node *temp = top1;
    cout << "Linked List:     ";
    while (temp != NULL)
    {
        cout << temp->data << "--> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

//Function For Reversing Linked List//

void reverse_ll()
{
    node *temp = top1;

    while (temp != NULL)
    {
        push_ll(temp->data);
        temp = temp->next;
    }
    temp = top1;
    while (temp != NULL)
    {
        temp->data = pop_ll();
        temp = temp->next;
    }
    cout << "Linked List Reversed Succesfully" << endl;
}

//Function for Creating Linked List//

void create_ll()
{
    int n;
    cout << "Enter the number of nodes in linked list: ";
    cin >> n;
    int data1;
    node *ptr = new node();
    cout << "Enter the data of node 1: ";
    cin >> data1;
    ptr->data = data1;
    ptr->next = NULL;
    top1 = ptr;
    for (int i = 1; i < n; i++)
    {
        cout << "Enter the data of node " << i + 1 << ": ";
        cin >> data1;
        node *newnode = new node();
        newnode->data = data1;
        newnode->next = NULL;
        ptr->next = newnode;
        ptr = newnode;
    }
}

//******DRIVER FUNCTION********//
int main()
{
    int n;
    do
    {
        cout << "******MAIN MENU********" << endl;
        cout << "1. Create a Linked List." << endl;
        cout << "2. Display Linked List." << endl;
        cout << "3. Reverse a Linked List." << endl;
        cout << "4. Exit." << endl;
        cout << "Enter any one of the above option: ";
        cin >> n;
        switch (n)
        {
        case 1:
            create_ll();
            break;
        case 2:
            Display();
            break;
        case 3:
            reverse_ll();
            break;
        case 4:
            return 0;
            break;
        }
    } while (n < 5);
}
