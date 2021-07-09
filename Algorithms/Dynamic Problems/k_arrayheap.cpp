// we are going to see two types of heap :
// 1- Max k-ary heap (key at root is greater than all descendants and same is recursively true for all nodes). 
// 2- Min k-ary heap (key at root is lesser than all descendants and same is recursively true for all nodes)

// lets start
#include<bits/stdc++.h>

using namespace std;

// function to heapify (or restore the max- heap property). This is used to build a k-ary heap and in extractMin()
// att[] -- Array that stores heap
void restoreDown(int arr[], int len, int index,int q)
// len -- Size of array, index -- index of element to be restored

{
	// child array to store indexes of all
	// the children of given node
	int child[q+1];

	while (1)
	{
	
		for (int i=1; i<=q; i++)
			child[i] = ((q*index + i) < len) ?
					(q*index + i) : -1;
		int max_child = -1, max_child_index ;

		// loop to find the maximum of all
		// the children of a given node
		for (int i=1; i<=q; i++)
		{
			if (child[i] != -1 &&
				arr[child[i]] > max_child)
			{
				max_child_index = child[i];
				max_child = arr[child[i]];
			}
		}

		// leaf node
		if (max_child == -1)
			break;

		// swap only if the key of max_child_index
		// is greater than the key of node
		if (arr[index] < arr[max_child_index])
			swap(arr[index], arr[max_child_index]);

		index = max_child_index;
	}
}

// Restores a given node up in the heap. This is used
// in decreaseKey() and insert()
void restoreUp(int arr[], int index, int k)
{
	// parent stores the index of the parent variable
	// of the node
	int parent = (index-1)/k;

	
	while (parent>=0)
	{
		if (arr[index] > arr[parent])
		{
			swap(arr[index], arr[parent]);
			index = parent;
			parent = (index -1)/q;
		}

		// node has been restored at the correct position
		else
			break;
	}
}

// Function to build a heap of arr[0..n-1] and alue of k.
void buildHeap(int arr[], int n, int q)
{
	// Heapify all internal nodes starting from last
	// non-leaf node all the way upto the root node
	// and calling restore down on each
	for (int i= (n-1)/q; i>=0; i--)
		restoreDown(arr, n, i, q);
}

void insert(int arr[], int* a, int q, int elem)
{
	// Put the new element in the last position
	arr[*a] = elem;

	// Increase heap size by 1
	*a = *a+1;

	// Call restoreUp on the last index
	restoreUp(arr, *a-1, q);
}


int extractMax(int arr[], int* a, int q
{
	// Stores the key of root node to be returned
	int max = arr[0];

	// Copy the last node's key to the root node
	arr[0] = arr[*a-1];

	// Decrease heap size by 1
	*a = *a-1;
	restoreDown(arr, *a, 0, q);

	return max;
}

// Main code begins here....
int main()
{
	const int capacity = 100;
	int arr[capacity] = {1, 3 ,5 , 7, 8, 9 , 10};
	int a = 7;
	int q = 3;

	buildHeap(arr, a, k);

	printf("Built Heap : \n");
	for (int i=0; i<a; i++)
		printf("%d ", arr[i]);

	int element = 3;
	insert(arr, &a, q, element);

	printf("\n\nHeap after inserting %d: \n",
			element);
	for (int i=0; i<a; i++)
		printf("%d ", arr[i]);

	printf("\n\nExtracted max is %d",
				extractMax(arr, &a, q

	printf("\n\nHeap after extract max: \n");
	for (int i=0; i<a; i++)
		printf("%d ", arr[i]);

	return 0;
}



/*
   
==========================================
   INPUT 
==========================================
   {1, 2 ,3 , 6, 8, 9 , 10}

==========================================
   OUTPUT:
==========================================   
   Built Heap : 
    10 9 3 6 8 1 2

    Heap after inserting of 3:
    10 9 3 6 8 1 2 3
==========================================
    Extracted max is 10
==========================================
    Heap after extract max:
    9 8 3 6 3 1 2
==========================================



    */
