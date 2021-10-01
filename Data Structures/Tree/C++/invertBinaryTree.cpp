#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
    public:
      Node *lchild;
      int data;
      Node *rchild;
};

class Tree
{
    private:
      Node *root;
    public:
      Tree();
      ~Tree();
      void createTree();
      void preOrder(Node *p);
      void preOrder() // Function overloading
      {
          preOrder(root);
      }
      void inOrder()
      {
          inOrder(root);
      }
      void postOrder()
      {
          postOrder(root);
      }
      void postOrder(Node *p);
      void inOrder(Node *root);
      void LevelOrder()
      {
          LevelOrder(root);
      }
      void LevelOrder(Node *p);
      int Height(Node *p);
      int Height()
      {
          return Height(root);
      }
      void IpostOrder()
      {
          IpostOrder(root);
      }
      void IpostOrder(Node *p);
      void IpreOrder(Node *p);
      void IpreOrder()
      {
          IpreOrder(root);
      }
      void IinOrder(Node *p);
      void IinOrder()
      {
          IinOrder(root);
      }
      void Mirror(Node *curr);
      Node* invertBinary(Node *p)
      {
          Mirror(root);
          return root;
      }
};

Tree::Tree()
{
    root = NULL;
}

Tree::~Tree()
{
    delete root;
}

void Tree::createTree()
{
    Node *p, *t;
    int x;
    queue<Node* >q; // This Queue will store the pointers of the Node as lchild and rchild.
    cout <<"Enter the root value\n";
    cin >>x;
    root = new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.emplace(root); //enqueue

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        cout <<"Enter left child data of "<<p->data<<endl;
        cin >>x;
        if (x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.emplace(t);
        }
        
        cout <<"Enter right child data of "<<p->data<<endl;
        cin >>x;
        if (x!=-1)
        {
            t = new Node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.emplace(t);
        }
    }
}

void Tree::preOrder(Node *p)
{
    if (p)
    {
        cout <<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void Tree::inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout <<p->data<<" ";
        inOrder(p->rchild);
    }
}

void Tree::postOrder(Node *p) {
    if (p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data <<" ";
    }
}

void Tree::IpostOrder(Node *p)
{
    stack<long int>st;
    cout <<"Using the Iterative Method Post Order: ";
    long int temp;

    while (p!=nullptr || !st.empty())
    {
        if (p!=nullptr)
        {
            st.emplace((long int)p);
            p = p->lchild;
        }
        else
        {
            temp = st.top();
            st.pop();
            if (temp > 0)    
            {
                st.emplace(-temp);
                p = ((Node*)temp)->rchild;
            }
            else
            {
                cout <<((Node*)(-1*temp))->data<<" ";
                p = nullptr;
            }
        }
    }
    cout <<endl;
}

void Tree::LevelOrder(Node *p)
{
    queue<Node *>q;
    cout <<root->data<<" ";
    q.emplace(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();

        if (p->lchild)
        {
            cout <<p->lchild->data<<" ";
            q.emplace(p->lchild);
        }
        if (p->rchild)
        {
            cout <<p->rchild->data<<" ";
            q.emplace(p->rchild);
        }
    }
}

void Tree::IpreOrder(Node *p)
{
    stack<Node *>st;
    cout <<"Using the Iterative Method Preorder: ";

    while (p || !st.empty())
    {
        if (p)
        {
            cout <<p->data<<" ";
            st.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            p = p->rchild;
        }
    }
    cout <<endl;
}

void Tree::IinOrder(Node *p)
{
    stack<Node *>st;
    cout <<"Using the Iterative Method Indorder: ";

    while (p || !st.empty())
    {
        if (p)
        {
            st.emplace(p);
            p = p->lchild;
        }
        else
        {
            p = st.top();
            st.pop();
            cout <<p->data<<" ";
            p = p->rchild;
        }
    }
    cout <<endl;
}
int Tree::Height(Node *p)
{
    int l =0;
    int r =0;
    if (p == NULL)
    {
        return 0;
    }
    l = Height(p->lchild);
    r = Height(p->rchild);

    if (l > r)
    {
        return l+1;
    }
    else
    {
        return r+1;
    }
    
}
void Tree::Mirror(Node *curr)
{
    if (curr == NULL)
    {
        return ;
    }
    
    // Post Order Traversal
    Mirror(curr->lchild);
    Mirror(curr->rchild);

    // Swapping the child pointers
    Node *temp;
    temp = curr->lchild;
    curr->lchild = curr->rchild;
    curr->rchild = temp;
}

int main()
{
    Tree bt;

    bt.createTree();
    cout <<endl;

    cout <<"Preorder : ";
    bt.preOrder();
    cout <<endl;

    cout <<"Inorder : ";
    bt.inOrder();
    cout <<endl;

    cout <<"Postorder : ";
    bt.postOrder();
    cout <<endl;
    
    bt.IpreOrder();
    bt.IinOrder();
    bt.IpostOrder();

    cout <<"Levelorder : ";
    bt.LevelOrder();
    cout <<endl;

    cout <<"Height of the Tree : ";
    cout <<bt.Height()<<endl;

    return 0;
}
