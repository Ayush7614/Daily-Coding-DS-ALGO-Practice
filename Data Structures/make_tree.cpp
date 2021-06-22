#include<iostream>
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
        void preOrder(Node*);
        void inOrder(Node*);
        void postOrder(Node*);
        Node* give_root() {return root;}
        void create_tree();
};

int main()
{
    Tree t1;
    t1.create_tree();
    Node *root = t1.give_root();  
    t1.inOrder(root);
    std::cout<<'\n';  
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