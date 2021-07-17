/*Link to probelm:
https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

*/

/*Algorithm:
We will implement this in three steps-
1. Add the cloned nodes after the original node like 1st original node next-> 1st cloned node
2. Connect random pointers with each cloned nodes
3. Removing all cloned nodes from original linked list

*/


#include<bits/stdc++.h>

using namespace std;

//Linked list Node
struct Node
{
    int data;
    Node* next;
    Node* arb;

    Node(int x)
    {
        data=x;
        next=NULL;
        arb=NULL;
    }

};


 Node *copyList(Node *head)
{
        Node *temp=head;
        Node *front=head;
        Node *copy;
        
        while(temp!=NULL) // adding cloned nodes in between original nodes
        {
            front=front->next;
            copy=new Node(temp->data);
            temp->next=copy;
            copy->next=front;
            temp=front;
            
        }
        
        temp=head;
        while(temp!=NULL) 
        {
            if((temp->arb)!=NULL)
            {
                temp->next->arb=temp->arb->next; // connecting random pointers with cloned nodes
                
            }
            
            temp=temp->next->next;
        }
        
        front=head;
        temp=head;
        
        Node *d=new Node(0); //dummy node whose next will contain head of cloned linked list
        copy=d;
        
        while(temp!=NULL) // obtainting original linked list
        {
            front=temp->next->next;
            copy->next=temp->next;
            temp->next=front;
            copy=copy->next;
            temp=temp->next;
        }
        
        return d->next;
        
        
}
      

// { Driver Code Starts.

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}


void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {


    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}



int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        struct Node *res = copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}  // } Driver Code Ends
    

/*
Input :
N = 4, M = 2
value = {1,2,3,4}
pairs = {{1,2},{2,4}}

Output: 1

*/