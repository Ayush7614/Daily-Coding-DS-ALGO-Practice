#include <iostream>
using namespace std;

struct node 
{
 int data;
 int height;
 struct node *left,*right;
};

class AVL_Tree
{ 
    public:
    struct node * root;
    AVL_Tree()
    {
        this->root = NULL;
    }
    
    // Function to return the height of the node
    int return_height(struct node *p)
    {
        if(p==NULL)
            return 0;
        else    
            return p->height;
    }

    // Function to return the maximum height
    int maxheight(int h1, int h2)
    {
        if(h1>h2)
            return h1;
        else
            return h2;
    }

    // Function to calculate Balance Factor
    int bf(struct node *n)
    {
        if(n==NULL)
            return 0;
        else
            return return_height(n->left)-return_height(n->right);
    }
    
    // Function to perform left rotation
    struct node* left_rotation(struct node *n)
    {
        struct node *p;
        struct node *tp,*temp;
        p = n;
        tp = p->right;
        temp = tp->left;
        tp->left = p;
        p->right = temp;
        p->height =  maxheight(return_height(p->left),return_height(p->right)) + 1;
        tp->height = maxheight(return_height(tp->left),return_height(tp->right)) + 1;
        return tp;
    }
    
    // Function to perform right rotation
    struct node* right_rotation(struct node *n)
    {
        struct node *p;
        struct node *tp,*temp;
        p = n;
        tp = p->left;
        temp = tp->right;
        tp->right = p;
        p->left = temp;
        p->height =  maxheight(return_height(p->left),return_height(p->right)) + 1;
        tp->height = maxheight(return_height(tp->left),return_height(tp->right)) + 1;
        return tp;
    }
    
    // Function to perform left-right rotation
    struct node* left_right_rotation(struct node *n)
    {
        struct node* p;
        struct node* tp;
        p=n;
        p->left=left_rotation(p->left);
        return right_rotation(p);
    }

    // Function to perform right-left rotation
    struct node* right_left_rotation(struct node *n)
    {
        struct node* p;
        struct node* tp;
        p=n;
        p->right= right_rotation(p->right);
        return left_rotation(p);
    }
    
    // Function to Display Level Order Traversal the AVL Tree
    void display_level_order(struct node* root)
    {
        int h = return_height(root);
        int i;
        for (i = 1; i <= h; i++)
            print_Level(root, i);
    }
    
    // Print nodes at a current level
    void print_Level(struct node* root, int level)
    {
        if (root == NULL)
            return;
        if (level == 1)
            cout << root->data << " ";
        else if (level > 1)
        {
            print_Level(root->left, level-1);
            print_Level(root->right, level-1);
        }
    }

    // Function to Display Pre-Order Traversal the AVL Tree
    void display_preorder(struct node* tree)
    {
        if(tree == NULL)
        { 
            return;
        }

        cout<<tree->data<<" ";
        display_preorder(tree->left);
        display_preorder(tree->right);
    }

    // Function to Insert a node in the AVL Tree
    struct node* Insert_Node(struct node *p,int data)
    { 
        if(p==NULL)
        {
            struct node *n;
            n = new struct node;
            n->data = data;
            p = n;
            p->left = p->right = NULL;
            p->height = 1; 
            return p; 
        }        
        else
        {
            if(data < p->data)
                p->left = Insert_Node(p->left,data);
            else
                p->right = Insert_Node(p->right,data);
            
            p->height = maxheight(return_height(p->left),return_height(p->right)) + 1;
            
            if(bf(p)==2 && bf(p->left)==1)
                p = right_rotation(p);
            
            else if(bf(p)==-2 && bf(p->right)==-1)
                p = left_rotation(p);
            
            else if(bf(p)==-2 && bf(p->right)==1)
                p = right_left_rotation(p);
            
            else if(bf(p)==2 && bf(p->left)==-1)
                p = left_right_rotation(p);
        } 
        return p;
    }
    
    // Function to Find the minimum node
    struct node * minimum(struct node * r)
    {
        while(r->left!=NULL)
        {
            r=r->left;    
        }
        return r;
    }
    
    // Function to Delete a node in the AVL Tree
    struct node* Delete_Node(struct node *p,int data)
    {        
        if(p==NULL)
            return p;
        else if(data < p->data)
            p->left = Delete_Node(p->left,data);
        else if(data > p->data)
            p->right = Delete_Node(p->right,data);
        else
        {
            struct node* temp = p;
            if(p->left==NULL)
            {
                p=p->right;
                free(temp);
            }    
            else if(p->right==NULL)
            {
                p=p->left;
                free(temp);
            }
            else    
            {
                temp = minimum(p->right);
                p->data = temp->data;
                p->right = Delete_Node(p->right,temp->data);
            }
        }
        
        if(bf(p)==2 && (bf(p->left)==1 || bf(p->left)==0))
        {
            p = right_rotation(p);
        }
        else if(bf(p)==-2 && (bf(p->right)==-1 || bf(p->right)==0) )
        {
            p = left_rotation(p);
        }
        else if(bf(p)==2 && bf(p->left)==-1)
        {
            p = left_right_rotation(p);
        }
        else if(bf(p)==-2 && bf(p->right)==1)
        {
            p = right_left_rotation(p);
        }

        return p;
    }

    // Function to Find a node in the AVL Tree
    bool Find_Node(struct node* p,int x)
    {
        struct node* temp = p;
        while(temp != NULL) 
        {
            if(temp->data == x) 
            {
                return true;
            } 
            else if(x < temp->data)
                temp = temp->left;
            else if(x > temp->data) 
                temp = temp->right;
        }
        return false;
    }

};

int main()
{
    AVL_Tree a;
    int opt,x;
    do
    {
        cout<<"\n1.Display AVL TREE ";
        cout<<"\n2.Insert Element ";
        cout<<"\n3.Delete Element ";
        cout<<"\n4.Search Element ";
        cout<<"\n\nEnter your choice: ";
        cin>>opt;
        
        switch (opt)
        {
            case 1:
                int o;
                if(a.root!=NULL)
                {
                    cout<<"1.Level-Order Traversal\n2.Pre-Order Traversal\n";
                    cin>>o;
                    if(o==1)
                    {
                        cout<<"\nLEVEL-ORDER TRAVERSAL\n\n";
                        a.display_level_order(a.root);
                    }
                    else if(o==2)
                    {
                        cout<<"\nPRE-ORDER TRAVERSAL\n\n";
                        a.display_preorder(a.root); 
                    }   
                }
                cout<<"\n";
                break;
            
            case 2:
                cout<<"Enter the Element to be inserted: ";
                cin>>x;
                a.root = a.Insert_Node(a.root,x);
                break; 
            
            case 3:
                cout<<"Enter the Element to be deleted: ";
                cin>>x;
                if(a.Find_Node(a.root,x))
                {
                    a.root = a.Delete_Node(a.root,x);
                    cout<<"\nElement Deleted\n";
                }
                else
                {
                    cout<<"\nElement Not found\n"; 
                }
                break;
            
            case 4:
                cout<<"Enter Element to be searched: ";
                cin>>x;
                if(a.Find_Node(a.root,x))
                {
                    cout<<"\nElement found\n";
                }
                else
                {
                    cout<<"\nElement Not found\n"; 
                }
                break; 
            
            default:
                cout<<"Ending Program...";
                break; 
        }

    }while(opt>0 && opt<5); 

    return 0;
}    