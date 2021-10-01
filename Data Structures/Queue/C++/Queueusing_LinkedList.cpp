#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int val;
    node* link;
    node(int num)
    {
        val = num;
        link = NULL;
    }
};
 
struct Queue{
    node *front, *rear;
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
 
    void enqueue(int x)
    {
        node* temp = new node(x);
        if (rear == NULL) {
            front = temp;
            rear = temp;    // adding first element
            return;
        }
        rear->link = temp;   //linking to next node and assigning the valye temp
        rear = temp;
        
    }
    void dequeue()
    {
        if (front == NULL){
            rear = NULL;
            return;             //no elements to delete
        }
        node* temp = front;
        front = front->link;       //removing element 1 by linking the head to the next node
    }
    void Display() {
        node* temp; 
        temp = front;
        if ((front == NULL) && (rear == NULL)) { // if front and rear ==null then no elements in queue
            cout<<"Empty Queue\n";
            return;
        }
        cout<<"Elements in the current Queue are : ";
        while (temp != NULL) {
            cout<<temp->val<<" ";     //printing from front to rear
            temp = temp->link;
        }
    }
};
 

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.Display();
    cout<<"\n";
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.dequeue();
    q.enqueue(80);
    q.dequeue();
    q.Display();
    cout<<"\n";
}
