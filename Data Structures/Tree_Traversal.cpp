/*
    This is a command line Tool
    Command Are:-
    * createTree
    * preOrder
    * inOrder
    * postOrder
    * levelOrder
    * count
    * height
    * exit
    Note:- These Commands are Case Sensitive
    ***Feel free to add your floavour***
*/
#include<iostream>
#include<stack>
#include<cstring>
#include<queue>

class Node
{
    public:
        Node *left;
        int data;
        Node *right;
        Node(int data = -1)
        {
            left = right = NULL;
            this->data = data;
        }
};

class Tree
{
    private:
        Node *root;
    public:
        Tree() {root = NULL;}
        void insert_tree();
        Node* give_root() {return root;}
        void preOrder(Node*);
        void inOrder(Node*);
        void postOrder(Node*);
        void levelOrder(Node*);
        int count(Node*);
        int height(Node*);
};

int main()
{
    char command[15];
    Tree t1;
    Node *root;
    while(1)
    {
        std::cout<<"command: "; // For entering command
        std::cin>>command;
        if(!strcmp(command, "exit"))
            break;
        else if(!strcmp(command, "createTree"))
            t1.insert_tree(),
            root = t1.give_root();
        else if(!strcmp(command, "preOrder"))
            t1.preOrder(root);
        else if(!strcmp(command, "inOrder"))
            t1.inOrder(root);
        else if(!strcmp(command, "postOrder"))
            t1.postOrder(root);
        else if(!strcmp(command, "levelOrder"))
            t1.levelOrder(root);
        else if(!strcmp(command, "count"))
            std::cout<<"count: "<<t1.count(root)<<'\n';
        else if(!strcmp(command, "height"))
            std::cout<<"height: "<<t1.height(root)<<'\n';
    }    
    return 0;
}

void Tree::insert_tree()
{
    int data;
    std::queue<Node*> Queue;
    Node *ptr, *tmp;
    std::cout<<"root: ";
    std::cin>>data;
    root = new Node(data);
    Queue.push(root);
    while(!Queue.empty())
    {
        ptr = Queue.front();
        Queue.pop();
        std::cout<<"Enter left child of "<<ptr->data<<": ";
        std::cin>>data;
        if(data != -1)
        {
            ptr->left = new Node(data);
            Queue.push(ptr->left);
        }
        std::cout<<"Enter right child of "<<ptr->data<<": ";
        std::cin>>data;
        if(data != -1)
        {
            ptr->right = new Node(data);
            Queue.push(ptr->right);
        }
    }
}

void Tree::preOrder(Node *root)
{
    std::stack<Node*> Stack;
    while(!Stack.empty() || root != NULL)
    {
        if(root != NULL)
        {
            std::cout<<root->data<<' ';
            Stack.push(root);
            root = root->left;
        }
        else
        {
            root = Stack.top();
            Stack.pop();
            root = root->right;
        }
    }
    std::cout<<"\n";
}

void Tree::inOrder(Node *root)
{
    std::stack<Node*> Stack;
    while(!Stack.empty() || root != NULL)
    {
        if(root != NULL)
        {
            Stack.push(root);
            root = root->left;
        }
        else
        {
            root = Stack.top();
            Stack.pop();
            std::cout<<root->data<<' ';
            root = root->right;
        }
    }
    std::cout<<"\n";
}

void Tree::postOrder(Node *root)
{
    std::stack<long int> Stack;
    while(!Stack.empty() || root != NULL)
    {
        if(root != NULL)
        {
            Stack.push((long int)root);
            root = root->left;
        }
        else
        {
            root = (Node*)Stack.top();
            Stack.pop();
            if((long int)root > 0)
            {
                Stack.push(-(long int)root);
                root = root->right;
            }
            else
            {
                root = (Node*)(-(long int)root);
                std::cout<<root->data<<' ';
                root = NULL;
            }
        }
    }
    std::cout<<"\n";
}

void Tree::levelOrder(Node *root)
{
    std::queue<Node*> Queue;
    Queue.push(root);
    Node *ptr;
    while(!Queue.empty())
    {
        ptr = Queue.front();
        Queue.pop();
        std::cout<<ptr->data<<' ';
        if(ptr->left) Queue.push(ptr->left);
        if(ptr->right) Queue.push(ptr->right);
    }
    std::cout<<'\n';
}

int Tree::count(Node *root)
{
    if(!root)
        return 0;
    int x, y;
    x = count(root->left);
    y = count(root->right);
    return x+y+1;
}

int Tree::height(Node *root)
{
    if(!root)
        return 0;
    int x=0, y=0;
    x = height(root->left);
    y = height(root->right);
    return (x>y)? x+1:y+1;
}
/*
Test Case 1:
INPUT
createTree 10 8 15 -1 -1 -1 -1 preOrder inOrder postOrder levelOrder height count exit

OUTPUT
10 8 15
8 10 15
8 15 10
10 8 15
height: 2
count: 3

Test Case 2:
INPUT
createTree 10 20 30 40 50 60 -1 -1 -1 -1 -1 -1 -1 preOrder inOrder postOrder levelOrder height count exit

OUTPUT
10 20 40 50 30 60
40 20 50 10 60 30
40 50 20 60 30 10
10 20 30 40 50 60
height: 3
count: 6
*/
