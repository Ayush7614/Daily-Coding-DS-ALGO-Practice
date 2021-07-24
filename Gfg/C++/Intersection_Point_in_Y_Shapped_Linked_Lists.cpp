//link to problem :
//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

/*Algorithm:
Keep traversing Linked list 1 and 2 with temp variable whenever one of the temp reaches null ,initiaze it with head of other 
linked list. If both temp become null return -1 (means no intersection) otherwise temp1=temp2 ,so return the common data.
*/

#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    if(head1==NULL && head2==NULL)
        return NULL;
        
    Node *temp1=head1; //initializing temp
    Node *temp2=head2;
    
    while(temp1!=temp2)
    {
        temp1= temp1==NULL? head2 : temp1->next; // if null then initialise with other linked list's head else move forward
        temp2= temp2==NULL? head1 : temp2->next;
    }
    
    if(temp1==NULL) //no intersection found
        return -1;
    
    return temp1->data;
    
    

}

// { Driver Code Starts
Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}


int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/*Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL
  */



