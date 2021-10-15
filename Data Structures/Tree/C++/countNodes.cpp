#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using namespace std;
template <typename T>

class TreeNode{
    public:
      T data;
      vector<TreeNode<T>*> children;  //constructor 
      TreeNode(T data){
          this->data=data;
      }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter Data "<<endl;
    cin>>rootData;
    TreeNode<int> *root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int> *front=pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter no of children of "<<front->data<<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child=new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(TreeNode<int> *root){
    queue<TreeNode<int>*> printingNodes;
    printingNodes.push(root);
    while(printingNodes.size()!=0){
        TreeNode<int> *front=printingNodes.front();
        printingNodes.pop();
        cout<<front->data<<": ";
        for(int i=0;i<front->children.size();i++){
            TreeNode<int> *child=front->children[i];
            cout<<child->data<<",";
            printingNodes.push(child);
        }
        cout<<endl;
    }
    
}
int countNodes(TreeNode<int> *root){
    int ans=1; //root node count 
    for(int i=0;i<root->children.size();i++){
        ans+=countNodes(root->children[i]);  //recursion
    }
    return ans;
}

int main()
{
    TreeNode<int> *root=takeInputLevelWise();
    cout<<countNodes(root);
    
    
}