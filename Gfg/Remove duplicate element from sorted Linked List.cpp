  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/
// root: head node
Node *removeDuplicates(Node *root)
{
 // your code goes here
 Node *p=root,*q;
 while(p!=NULL){
    while(p->next && p->data==p->next->data){
        q=p->next;
        p->next=q->next;
        q->next=NULL;
        delete q;
        
    }
    p=p->next;
 }
 return root;
}
