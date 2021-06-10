#include <iostream>
using namespace std;

class Node{         //declaring node as a class

    public:
        int key;
        Node *next;

        Node()
        {
            key = 0;
            next = NULL;
        }
        Node(int k)
        {
            key = k;
            next = NULL;
        }
};

class SinglyLinkedList          //declaring list as a class
{
    public:
        Node* head; 

        SinglyLinkedList()
        {
            head = NULL;
        }
        SinglyLinkedList(Node* n)
        {
            head = n;

        }

        Node* nodeExists(int k)         //defining a method to see if node exists
        {
            Node* temp = NULL;
            Node* ptr = head;

            while(ptr != NULL)
            {
                if(ptr->key==k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }

        void appendNode(Node* n)            //defining a method to append the node to the list
        {
            if(nodeExists(n->key) != NULL)
            {
                cout << "Node Already Exists with key value: "<< n->key <<". Append with some other key value."<<endl;
            }
            else
            {
                if(head == NULL)
                {
                    head = n;
                }
                else
                {
                    Node* ptr = head;
                    while(ptr->next != NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                }
            }
        }

        void printlist()            //defining a member to print the loop
        {
            if(head == NULL)        //when linkedlist is empty
            {
                cout<<"No nodes in this list"<<endl;
            }
            else
            {
                cout<<"Singly linked list values are as follows: "<<endl;
                Node* temp = head;

                while(temp != NULL)
                {
                    cout<<""<<temp->key<<" -> ";
                    temp = temp->next;
                }
                cout<<"NULL"<<endl;
            }
        }

};

void checkLoop(SinglyLinkedList n)          //userdefined function to check whether a list has a loop or not
{
    Node* ptr1 = new Node();        //declaring pointers to transverse through the list
    Node* ptr2 = new Node();        //declaring pointers to transverse through the list

    ptr1 = n.head;
    ptr2 = n.head->next;

    while(ptr2->next != NULL  && ptr2->next->next != NULL)
    {
        ptr1 = ptr1->next;              // one travels slow and the other travels fast. Here, if there is no loop. faster pointer--
        ptr2 = ptr2->next->next;        // --will reach NULL and if it is a loop, at one point or the other, they will meet each other
        if(ptr1 == ptr2)
        {
            break;
        }

    }
     if(ptr1 == ptr2)               //output to give answer to the user
    {
        cout<<"Loop is found"<<endl;
    }
    else{
        cout<<"No loop found and ";
        n.printlist();
        cout<<endl;
    }
}

int main()
{
    
    SinglyLinkedList sl1, sl2, sl3;

    //Here, s1 is a circular list.
    /*0 --> 1  ---->    4
            ^           |
            |           v
            25 <- 16 <- 9 */
    for(int i = 0; i<4;i++)
    {
        Node* temp1 = new Node(i*i);
        sl1.appendNode(temp1);
    }
    Node* temp1 = new Node();
    temp1->key = 25;
    sl1.appendNode(temp1);
    temp1->next = sl1.head->next;
    cout<<"Cheking loop for sl1.\nAnswer:";
    checkLoop(sl1);
    cout<<endl;
    cout<<endl;

    // Here, sl2 is a linear list.
    // 0 -> 1-> 4 -> 9 -> 16 -> 25 -> 36 -> 49 -> 64 -> 81 -> NULL
    for(int i = 0; i<10;i++)
    {
        Node* temp2 = new Node(i*i);
        sl2.appendNode(temp2);
    }
    cout<<"Cheking loop for sl2.\nAnswer:";
    checkLoop(sl2);
    cout<<endl;
    cout<<endl;

    //Here, sl3 is the example list given in the question.
    /* 1 -> 2 -> 3 ---
                 ^    |
                 |    v
                 5 <- 4*/
    for(int i = 0; i<4;i++)
    {
        Node* temp3 = new Node(i+1);
        sl3.appendNode(temp3);
    }
    Node* temp3 = new Node(5);
    sl3.appendNode(temp3);
    temp3->next = sl3.head->next->next;
    cout<<"Cheking loop for sl3.\nAnswer:";
    checkLoop(sl3);
    
    
}