//         Sort of 0s,1s and 2s
// Link of the problem:- https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

// Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array. The functions should put all 0s first, then all 1s and all 2s in last.
// Examples: 
 
// Input: {0, 1, 2, 0, 1, 2}
// Output: {0, 0, 1, 1, 2, 2}

// Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
// Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}

#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void dnfSort(int arr[],int n)
{
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr,mid,low);
            mid++;
            low++;
        }

        else if(arr[mid]==1)
        {
            mid++;
        }
        else if(arr[mid]==2)
        {
            swap(arr,mid,high);
            high--;
        }
    }
}

int main()
{
    int arr[]={1,0,2,1,0,1,2,1,2};
    dnfSort(arr,9);

    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

// Explaination:- In this solution we have 3 pointers low,high and mid. We had put different conditions.