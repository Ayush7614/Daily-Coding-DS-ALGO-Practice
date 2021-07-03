//---------FRACTIONAL KNAPSACK---------//

/*
Problem link is:https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

Problem Statement:Given weights and values of N items, we need to put these items in a knapsack
of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item. 
*/

/* 
Logic :
An efficient solution is to use Greedy approach. The basic idea of the greedy approach is to 
calculate the ratio value/weight for each item and sort the item on basis of this ratio. Then
take the item with the highest ratio and add them until we can’t add the next item as a whole 
and at the end add the next item as much as we can. Which will always be the optimal solution 
to this problem.
A simple code with our own comparison function can be written as follows, please see sort function 
more closely, the third argument to sort function is our comparison function which sorts the item 
according to value/weight ratio in non-decreasing order. 
After sorting we need to loop over these items and add them in our knapsack satisfying above-mentioned
criteria.

*/

#include <bits/stdc++.h>
using namespace std;

// class is initiated to store the value and weight of items
struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

/* 
cnp() is a comparison function used in sort function to sort 
the items in a definite manner. 
*/
bool cnp(struct Item a,struct Item b)
{
    double x=(double)a.value/(double)a.weight;
    double y=(double)b.value/(double)b.weight;
    return x>y;
}

// function to return fractionalweights
class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
    sort(arr,arr+n,cnp);
   int i=0;
   double value=0;
 
   while(W!=0 && i<n)
   {
       if(W>=arr[i].weight)
       {
           W-=arr[i].weight;
           value+=arr[i].value;
       }
       else
       {
           double x=(double)arr[i].value/(double)arr[i].weight;
           x=x*W;
           W=0;
           value+=x;
       }
       i++;
   }
    return value;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends