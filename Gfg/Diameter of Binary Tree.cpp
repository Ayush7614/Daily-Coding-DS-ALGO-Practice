{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
/* Computes the diameter of binary tree with given root.  */
int dim(Node *root,int &ref){
    if(root==NULL)
   return 0;
   int l=dim(root->left,ref);
   int r=dim(root->right,ref);
   int loc=1+max(l,r);
   int glob=1+l+r;
   ref=max(glob,ref);
   return loc;
   
}

int diameter(Node* root)
{
    int ref;
    dim(root,ref);
   return ref;
}
