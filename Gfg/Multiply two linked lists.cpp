/**

Problem Link: https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1

Example:
Input:
2
2
3 2
1
2
3
1 0 0
2
1 0 

Output:
64
1000

Explanation:
Testcase 1: 32*2 = 64.
Testcase 2: 100*10 = 1000.

*/


#include<bits/stdc++.h>
using namespace std;

// Linked List Node.
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

// Function to create a new node with given data.
struct Node *newNode(int data)
{
    struct Node *new_node = new Node(data);
    return new_node;
}

// To insert a node in the linked list.
void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = newNode(new_data);
   
    // link the old list off the new node
    new_node->next = (*head_ref);
   
    // move the head to point to the new node
    (*head_ref) = new_node;
}  

// To reverse the linked list
void reverse(Node** r)
{
    Node* prev=NULL;
    Node* cur=*r;
    Node* nxt;
    
    while(cur!=NULL)
    {
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    
    *r=prev;
}

// To delete the linked list.
void freeList(struct Node *Node)
{
    struct Node* temp;
    
    while(Node!=NULL)
    {
        temp=Node;
        Node=Node->next;
        free(temp);
    }
    
}

// To multiply contents of two linked lists
long long  multiplyTwoLists (Node* l1, Node* l2)
{
    Node* a=l1;
    Node* b=l2;
    long long n1=0,n2=0,m=1000000007;
    
    while(a)
    {
        n1=(n1*10)%m+a->data;
        a=a->next;
    }
    
    while(b)
    {
        n2=(n2*10)%m+b->data;
        b=b->next;
    }
    
    return (n1%m * n2%m)%m;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct Node* first = NULL;
        struct Node* second = NULL;
   
        int n,m,i,x;
        
        // Size of first list
        cin>>n; 
        for(i=0;i<n;i++)
        {
            cin>>x;
            //inserting nodes in first list
            push(&first,x);
        }
        
        // Size of second list
        cin>>m; 
        for(i=0;i<m;i++)
        {
            cin>>x;
            //inserting nodes in second list
            push(&second,x);
        }
        
        //reversing the lists.
        reverse(&first);
        reverse(&second);
        
        // Multiply the two linked lists and print the result
        cout<<"Result is: ";
        cout<<multiplyTwoLists(first, second)<<"\n";
        
        // deleting the lists.
        freeList(first);
        freeList(second);
    
    }
    
    return 0;
}