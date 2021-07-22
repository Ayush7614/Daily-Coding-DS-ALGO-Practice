// BINARY TREE TRAVERSAL TECHNIQUES USING RECURSION
#include <iostream>
using namespace std;
#define MAX 200
template<class t>
class queue
{
    public:					//CREATING A CLASS QUEUE TO STORE TREE VALUES FOR TRAVERSAL
    int front,rear;			
    t a[MAX];
    int size;
    queue(int len)			//CONSTRUCTOR FOR INITIALIZATION
    {
    	front=0;
    	rear=0;
        size=len;
    }

    void enqueue(t i)			//FUNCTION TO ADD AN ELEMENT IN A QUEUE
    {
        if(rear != size)
        {
            if(rear==0)
            {
                a[front] = i;
                rear++;
            }
            else
            {
                a[rear] = i;
                rear++;
            }
        }
        else
            cout<<"Queue is full";    
    }
    void dequeue()				//FUNCTION TO POP/REMOVE A VALUE FROM A QUEUE
    {
        if(front == rear)
            cout<<"The queue is empty";
        else
        {
            for(int i=0;i<rear-1;i++)
                a[i] = a[i+1];
            rear--;
        }
    }
    t get_firstelement()		//FUNCTION TO GET FIRST ELEMENT OF A QUEUE
    {
        if(front == rear)
            return 0;
        else
            return a[front];
    }
    int isempty()			//CHECKS IF A QUEUE IS EMPTY AND RETURNS TRUE IF EMPTY
    {
    	if(front==rear)
    		return 1;
    	else
    		return 0;
    }

};
//INCLUDE ARRAY QUEUE CLASS HERE WITHOUT MAIN
template <class T>
struct Node 
{
	T element;
	Node<T> *left, *right; 
	Node()
	{
		left = right = NULL; 
	}
	Node(T e) 
	{
		element=e;
		left = right = NULL;
	}
	Node(T e, Node<T> *lc, Node<T> *rc) 
	{
		element=e;
		left = lc;
		right = rc; 
	}
};

template <class T> 
void visit(Node<T> *x) 
{
	cout << x->element <<' '; 
}

template <class T>
void preOrder(Node<T> *t) 
{
	if (t != NULL) 
	{
		visit(t);
		preOrder(t->left); // do left subtree 
		preOrder(t->right); // do right subtree
	} 
}

template <class T>
void inOrder(Node<T> *t) 
{
	if (t != NULL) 
	{
		inOrder(t->left); //do left subtree
		visit(t); // visit tree root 
		inOrder(t->right); // do right subtree
	}
}

template <class T>
void postOrder(Node<T> *t) 
{
	if (t != NULL) 
	{
		postOrder(t->left); //do left subtree
		postOrder(t->left); //do right subtree
		visit(t); // visit tree root 
	}
}

template <class T>
void levelOrder(Node<T> *t) 
{
	queue<Node<T>*> q(10); 
	while (t != NULL)
	{
		visit(t); // visit t
		// put t's children on queue
		if (t->left != NULL)
			q.enqueue(t->left); 
		if (t->right != NULL)
			q.enqueue(t->right);

		// get next node to visit 
		if(!q.isempty())
		{
			t = q.get_firstelement();
			q.dequeue(); 
		}
		else
			return;
	}
}

int main(void) 
{
	Node<int> *n1, *n2, *n3,*n4,*n5; 	// DATATYPE OF THE BINARY TREE IS T i.e int
	bool b;int k;						// IT IS DECIDED WHILE CREATING AN OBJECT
	n1= new Node<int> (4);
	n2= new Node<int> (5);				// here n1,n2,n3,n4,n5 NODES ARE OF INTEGER TYPE
	n3= new Node<int> (2,n1,n2); 
	n4= new Node<int> (3);				//				1
	n5= new Node<int> (1,n3,n4);		//			   / \									/
	cout <<"Inorder sequence is ";		//			  2	  3
	inOrder(n5);						//			 / \									/	
	cout << endl;						//			4   5
	cout <<"Preorder sequence is ";			
	preOrder(n5);						//THIS IS THE BINARY TREE FORMED FROM THE GIVEN VALUES
	cout << endl;
	cout <<"Postorder sequence is "; 	
	postOrder(n5);
	cout << endl;
	cout <<"Level order sequence is "; 
	levelOrder(n5);
	cout << endl<<endl;
	cout<<"The given tree was \n";
	cout<<"		    1\n";
	cout<<"		   / \\ \n";
	cout<<"		  2   3\n";
	cout<<"		 / \\ \n";
	cout<<"		4   5\n";
}