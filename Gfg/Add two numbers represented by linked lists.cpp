
/* Problem Link : https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1 */

/**
Input: 
List1: 5->6->3 // represents number 365 
List2: 8->4->2 // represents number 248 
Output: 
Resultant list: 3->1->6 // represents number 613 
Explanation: 365 + 248 = 613
*/

#include <bits/stdc++.h>
using namespace std; 

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

struct Node* buildList(int size)
{
    int v;
    cin>>v;
    
    Node* head=new Node(v);
    Node* tail=head;
    
    for(int i=0;i<size-1;i++)
    {
        cin>>v;
        tail->next=new Node(v);
        tail=tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    
    cout<<"\n";
}

class Solution
{
    public:
    //reversing the Linked Lists
    struct Node* reverse(struct Node* head)
    {
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        
        return head;
    }
    
    //function to add two numbers represented by Linked Lists
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        long long int sum=0,carry=0;
        struct Node* f=reverse(first);
        struct Node* s=reverse(second);
        struct Node* head=NULL;
        struct Node* tail=NULL;

        while(f && s)
        {
            //calculating the sum of two digits and adding the carry (if present)
            sum= f->data+s->data+carry;
            //updating the carry 
            carry=(sum>9)?sum/10:0;
            //updating the value of sum
            sum=sum%10;
            //inserting value in final linked list
            struct Node* n=new Node(sum);
            
            if(head==NULL)
            {
                head=n;
                tail=n;
            }
            else
            {
                tail->next=n;
                tail=n;
            }

            f=f->next;
            s=s->next;
        }
        
        //to add the values which may be left if size of f is greater than s
        while(f)
        {
            sum=carry+f->data;
             carry=(sum>9)?sum/10:0;
            
            sum=sum%10;
            
            struct Node* n=new Node(sum);
            
            if(head==NULL)
            {
                head=n;
                tail=n;
            }
            else
            {
                tail->next=n;
                tail=n;
            }
            
            f=f->next;
            
        }
        
        //to add the values which may be left if size of s is greater than f
        while(s)
        {
            sum=carry+s->data;
             carry=(sum>9)?sum/10:0;
            
            sum=sum%10;
            
            struct Node* n=new Node(sum);
            
            if(head==NULL)
            {
                head=n;
                tail=n;
            }
            else
            {
                tail->next=n;
                tail=n;
            }
            
            s=s->next;
        }
        
        //adding the carry if present
        if(carry)
        {
            struct Node* n=new Node(carry);
            tail->next=n;
            tail=n;
        }
        //reversing the final linked list
        head=reverse(head);
        //returning the head of the final linked list
        return head;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        Node* first=buildList(n);//input for 1st list
        
        cin>>m;
        Node* second=buildList(m);//input for second list
        
        Solution ob;
        
        Node* res=ob.addTwoLists(first,second); //to add the two lists
        
        printList(res); //printing the final list
    }
    
    return 0;
}