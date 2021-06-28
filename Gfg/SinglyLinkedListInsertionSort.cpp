/*Problem : Insertion Sort for Singly Linked List*/

/*Explanation of problem : Given a Singly Linked List, the task is to sort the elements of the linked list using Insertion Sort*/
// C++ program to sort link list using insertion sort
#include <iostream>
using namespace std;

struct Node //Defining the structure Node
{
    int val;           //for storing the element
    struct Node *next; // for storing the address of the next node
    Node(int a)        //Parametrized Constructor
    {
        val = a;
        next = NULL;
    }
};

class singly_ll
{

public:
    Node *head;
    Node *sorted;

    void push(int val)
    {
        /* allocate node */
        Node *newnode = new Node(val);
        /* link the old list off the new node */
        newnode->next = head;
        /* move the head to point to the new node */
        head = newnode;
    }
    void insertionSort(Node *headref) // function to sort a singly linked list using insertion sort
    {
        sorted = NULL; // Initialize sorted linked list
        Node *current = headref;
        while (current != NULL) // Traverse the given linked list and insert every node to sorted
        {
            // Store next for next iteration
            Node *next = current->next;
            // insert current in sorted linked list
            sortedInsert(current);
            // Update current
            current = next;
        }

        head = sorted; // Update head_ref to point to sorted linked list
    }

    /*
      function to insert a new_node in a list. Note that
     this function expects a pointer to head_ref as this
     can modify the head of the input linked list
     (similar to push())
     */
    void sortedInsert(Node *newnode)
    {
        /* Special case for the head end */
        if (sorted == NULL || sorted->val >= newnode->val)
        {
            newnode->next = sorted;
            sorted = newnode;
        }
        else
        {
            Node *current = sorted;
            while (current->next != NULL && current->next->val < newnode->val) /* Locate the node before the point of insertion*/
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }
    void printlist(Node *head) /* Function to print linked list */
    {
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
    }
};

int main() //Main Function
{
    singly_ll list;
    list.head = NULL;
    list.push(5);
    list.push(20);
    list.push(4);
    list.push(3);
    list.push(30);
    cout << "Linked List before sorting : " << endl;
    list.printlist(list.head);
    cout << endl;
    list.insertionSort(list.head);
    cout << "Linked List After sorting : " << endl;
    list.printlist(list.head);
}
/*
   Time Complexity : O(n) 
   Space Complexity : O(n)

   OUTPUT :
    Linked List before sorting : 
    30 3 4 20 5
    Linked List After sorting :
    3 4 5 20 30
*/