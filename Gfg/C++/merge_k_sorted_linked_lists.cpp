//Link to probelm:
//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1

/*Algorithm:
We will use divide an conquer technique. We will keep merging the last linkedlist in first linked list.
*/

// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


class Solution{
  public:
    
    //Function to merge two linkedlist
      Node* mergeTwoLists(Node* l1,Node* l2) {
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        Node *res=NULL;
        if(l1->data <= l2->data)
        {
            res=l1;
            res->next=mergeTwoLists(l1->next,l2);
            
        }
        else
        {
            res=l2;
            res->next=mergeTwoLists(l1,l2->next);
            
        }
            
    
        return res;
        
        
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
           int i=0,last=k-1;
           int j;
           
           while(last!=0)
           {
               i=0;
               j=last;
               while(i<j)
               {
                   arr[i]= mergeTwoLists(arr[i],arr[j]);
                   i++;
                   j--;
               }
               if(i>=j)
                 last=j;
           }
           
           return arr[0];
    }
};

// { Driver Code Starts.
/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends
 
  // Time Complexity: O(n logk)
  // Space Complexity: O(n)

/*
Input:
K = 3
value = {{1,3},{4,5,6},{8}}

Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.
*/