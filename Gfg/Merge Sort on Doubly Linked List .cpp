// Merge Sort on Doubly Linked List 

/* Given Pointer/Reference to the head of a doubly linked list of N nodes, the task is to Sort the 
   given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.  */



#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};
/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


//Function to sort the given doubly linked list using Merge Sort.
void Split(Node* head, Node** a, Node** b) 
{ 
    Node* fast = head->next; 
    Node* slow = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
  
    *a = head; 
    *b = slow->next; 
    slow->next = NULL; 
} 

Node *SortedMerge(Node *a, Node *b)
{
    if(a == NULL)
    {
        return b;
    }
    
    if(b == NULL)
    {
        return a;
    }
    
    Node *head = NULL, *tail = NULL;
    if(a->data < b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }
    
    while(a != NULL && b != NULL)
    {
        if(a->data < b->data)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    
    if(a == NULL)
    {
        tail->next = b;
    }
    else
    {
        tail->next = a;
    }
    
    Node *curr = head, *prev = NULL;
    while(curr != NULL)
    {
        curr->prev = prev;
        prev = curr;
        curr = curr->next;
    }
    
    return head;
}

void MergeSort(Node **headRef)
{
    Node* head = *headRef; 
    
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    Node* a, * b;
    Split(head, &a, &b); 
  
    MergeSort(&a); 
    MergeSort(&b); 
  
    *headRef = SortedMerge(a, b); 
}

struct Node *sortDoubly(struct Node *head)
{
	MergeSort(&head);
    
    return head;
}


void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}

int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}



/*  
    Input:
        N = 5
        value[] = {9,15,0,-1,0}
    Output:
        -1 0 0 9 15
        15 9 0 0 -1
    Explanation: 
       After sorting the given linked list in both ways, the resultant list will be -1 0 0 9 15 in non-decreasing order and  15 9 0 0 -1 in non-increasing order.  */
