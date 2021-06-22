#include<iostream>
#include<queue>
#include<cstring>

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
        void preOrder(Node*);
        void inOrder(Node*);
        void postOrder(Node*);
        Node* give_root() {return root;}
        void create_tree();
};

int main()
{
    char command[15];
    Tree t1;
    Node *root;
    while(1)
    {
        std::cout<<"command: ";
        std::cin>>command;
        if(!strcmp(command, "exit"))
            break;
        else if(!strcmp(command, "createTree"))
            t1.create_tree(),
            root = t1.give_root();
        else if(!strcmp(command, "preOrder"))
            t1.preOrder(root),
            std::cout<<'\n';
        else if(!strcmp(command, "postOrder"))
            t1.postOrder(root),
            std::cout<<'\n';
        else if(!strcmp(command, "inOrder"))
            t1.inOrder(root),
            std::cout<<'\n';
    }
    return 0;
}

void Tree::create_tree()
{
    int data;
    std::cout<<"root: ";
    std::cin>>data;
    root = new Node(data);
    std::queue<Node*> Queue;
    Queue.push(root);
    Node *ptr;
    while(!Queue.empty())
    {
        ptr = Queue.front();
        Queue.pop();
        std::cout<<"Left of "<<ptr->data<<": ";
        std::cin>>data;
        if(data != -1)
        {
            ptr->left = new Node(data);
            Queue.push(ptr->left);
        }
        std::cout<<"Right of "<<ptr->data<<": ";
        std::cin>>data;
        if(data != -1)
        {
            ptr->right = new Node(data);
            Queue.push(ptr->right);
        }
    }
}

void Tree::inOrder(Node *root)
{
    if(!root)
        return;
    inOrder(root->left);
    std::cout<<root->data<<' ';
    inOrder(root->right);   
}

void Tree::postOrder(Node *root)
{
    if(!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->data<<' ';   
}

void Tree::preOrder(Node *root)
{
    if(!root)
        return;
    std::cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
}