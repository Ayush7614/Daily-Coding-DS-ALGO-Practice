//You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given.
//Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a tail node in the linked list.
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

Node *findNode(Node* head, int search_for)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}


void insert()
{
    int n,i,value;
    Node *temp;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=new Node(value);
            temp=head;
            continue;
        }
        else
        {
            temp->next= new Node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}

/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}



 // } Driver Code Ends



class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // Your code here
       del->data=del->next->data;
       del->next=del->next->next;
    }

};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

    int t,k,n,value;
    
    scanf("%d",&t);
    while(t--)
    {
        insert();
        scanf("%d",&k);
        Node *del = findNode(head, k);
        Solution ob;
        if (del != NULL && del->next != NULL)
        {
            ob.deleteNode(del);
        }
        printList(head);
    }
    return(0);
}


  // } Driver Code Ends

//Test Cases:
/*
Input:
N = 2
value[] = {1,2}
node = 1
Output: 2
_____________________________________

Input:
N = 4
value[] = {10,20,4,30}
node = 20
Output: 10 4 30

*/

//Time complexity
/*
For deleting node: O(N)

Auxiliary Space: O(1)

*/
