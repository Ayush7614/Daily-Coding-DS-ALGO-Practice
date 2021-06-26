//Segment Tree ----- Implementation of operation like construction, query and update
//Time Complexity for tree construction is O(n). There are total 2n-1 nodes, and value of every node is calculated only once in tree construction
//Time complexity to query is O(Logn). To query a sum, we process at most four nodes at every level and number of levels is O(Logn).
//The time complexity of update is also O(Logn). To update a leaf value, we process one node at every level and number of levels is O(Logn)

/*

Test Case : 1 ----------------------
# input
arr[ ]={1,3,5,7,9,11}
# output
Printing the nodes of segment tree built using the given array :
1 3 4 5 9 7 9 16 11 27 36

Sum of values in the range is (1,3) : 15
Sum of values in the range is (-1,3) : -1

Sum of values in the range is (1,3) after update : 22
Sum of values in the range is (-1,3) after update : -1

Test Case : 2 -----------------------
# input
arr[ ]={2,3,5,6,2,3,8,9,7}

# output
Printing the nodes of segment tree built using the given array :
2 3 5 5 10 6 2 8 18 3 8 11 9 7 16 27 45

Sum of values in the range is (1,3) : 14
Sum of values in the range is (-1,3) : -1

Sum of values in the range is (1,3) after update : 21
Sum of values in the range is (-1,3) after update : -1

*/


#include<bits/stdc++.h>
using namespace std;
//----------------------------------------------------------------------------------------getmid function-----------
// A utility function to get the middle index from corner indexes.
int getmid(int s,int e)
{
	return s+(e-s)/2;
}
//-----------------------------------------------------------------------------------------construction----------------------------
// A recursive function that constructs Segment Tree for array[ss..se].  
// si is index of current node in segment tree st
int constructSTUtil(int arr[ ],int ss,int se,int *st,int si)
{
	// If there is one element in array, store it in current node of  
    // segment tree and return 
	if(ss==se)
	{
		st[si]=arr[ss];
		cout<<st[si]<<" ";//----------------------------------------------- for printing segment tree
		return arr[ss];
	}
	// If there are more than one elements, then recur for left and 
    // right subtrees and store the sum of values in this node
    int mid=getmid(ss,se);
    st[si]=constructSTUtil(arr,ss,mid,st,2*si+1)+constructSTUtil(arr,mid+1,se,st,2*si+2);
    cout<<st[si]<<" ";//----------------------------------------------- for printing segment tree
    return st[si];
}
/* Function to construct segment tree from given array. This function  
allocates memory for segment tree and calls constructSTUtil() to  
fill the allocated memory */
int *constructST(int arr[ ],int n)
{
	// Allocate memory for the segment tree  
  
    //Height of segment tree
    int x=(int )(ceil(log2(n)));//--------- means upper bound of log2n
    //Maximum size of segment tree 
    int maxsize=2*(int)pow(2,x)-1;
    // Allocate memory for segment tree
    int *st=new int[maxsize];
    // Fill the allocated memory st
    constructSTUtil(arr,0,n-1,st,0);
    // Return the constructed segment tree 
    return st;
}
//-------------------------------------------------------------------------------------------------getsum------------------
/* A recursive function to get the sum of values in the given range  
    of the array. The following are parameters for this function.  
  
    st --> Pointer to segment tree  
    si --> Index of current node in the segment tree. Initially  
            0 is passed as root is always at index 0  
    ss & se --> Starting and ending indexes of the segment represented  
                by current node, i.e., st[si]  
    qs & qe --> Starting and ending indexes of query range */
int getsumUTil(int *st,int ss,int se,int qs,int qe,int si)
{
	// If segment of this node is a part of given range, then return  
    // the sum of the segment-----------------------------------------case 1
    if(qs<=ss && qe>=se)
    return st[si];//node is the sum
    // If segment of this node is outside the given range-----------------------------------------case 2
    if(se<qs || ss>qe)
    return 0;
    // If a part of this segment overlaps with the given range-----------------------------------------case 3
    int mid=getmid(ss,se);
    return getsumUTil(st,ss,mid,qs,qe,2*si+1)+getsumUTil(st,mid+1,se,qs,qe,2*si+2);
}
// Return sum of elements in range from index qs (quey start)  
// to qe (query end). It mainly uses getSumUtil()
int getsum(int *st,int n,int qs,int qe)
{
	// Check for erroneous input values
	if(qs<0 || qe>n-1 || qs>qe)
	{
//		cout<<"Invalid Input"<<endl;
		return -1;
	}
	return getsumUTil(st,0,n-1,qs,qe,0);
}
//-----------------------------------------------------------------------------------------------------------------updatevalue------------------
/* A recursive function to update the nodes which have the given  
index in their range. The following are parameters  
    st, si, ss and se are same as getSumUtil()  
    i --> index of the element to be updated. This index is  
            in the input array.  
diff --> Value to be added to all nodes which have i in range */
void updatevalueUtil(int *st,int ss,int se,int i,int diff,int si)//----update only one element of array
{
	// Base Case: If the input index lies outside the range of  
    // this segment
    if(i<ss || i>se)
    return ;
    // If the input index is in range of this node, then update  
    // the value of the node and its children
    st[si]=st[si]+diff;
    if(ss!=se)
    {
    	int mid=getmid(ss,se);
    	updatevalueUtil(st,ss,mid,i,diff,2*si+1);
    	updatevalueUtil(st,mid+1,se,i,diff,2*si+2);
	}
}
// The function to update a value in input array and segment tree.  
// It uses updateValueUtil() to update the value in segment tree
void updatevalue(int arr[],int *st,int n,int i,int newval)
{
	// Check for erroneous input index
	if(i<0 || i>n-1)
	{
//		cout<<"Invalid Input."<<endl;
		return ;
	}
	// Get the difference between new value and old value
	int diff=newval-arr[i];
	// Update the value in array
	arr[i]=newval;
	// Update the values of nodes in segment tree
	updatevalueUtil(st,0,n-1,i,diff,0);
}
int main()
{
	int arr[ ]={1,3,5,7,9,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Printing the given input array :\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
	cout<<"Printing the nodes of segment tree built using the given array :\n";
	// Build segment tree from given array
	int *st=constructST(arr,n);
	int n1=sizeof(st)/sizeof(int);
	cout<<endl<<endl;
//	cout<<n1<<endl;
//	for(int i=0;i<n1;i++)
//	{
//		cout<<st[i]<<" ";
//	}
//	cout<<endl<<endl;
	int sum=getsum(st,n,1,3);
	cout<<"Sum of values in the range is (1,3) : "<<sum<<endl;
	sum=getsum(st,n,-1,3);
	cout<<"Sum of values in the range is (-1,3) : "<<sum<<endl<<endl; // since the input is not valid, we get range sum as -1
	
	updatevalue(arr,st,n,1,10); // updating the array element 
	
	sum=getsum(st,n,1,3);
	cout<<"Sum of values in the range is (1,3) after update : "<<sum<<endl;
	sum=getsum(st,n,-1,3);
	cout<<"Sum of values in the range is (-1,3) after update : "<<sum<<endl; // since the input is not valid, we get range sum as -1
//	for(int i=0;i<n;i++)
//	{
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<n1;i++)
//	{
//		cout<<st[i]<<" ";
//	}
//	cout<<endl;
	return 0;
}
