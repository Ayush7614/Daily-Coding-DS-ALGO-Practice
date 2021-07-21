//         Geeks For Geeks Ques 
//         Union And Intersection 
    
// Link of the problem: https://www.geeksforgeeks.org/union-and-intersection-of-two-sorted-arrays-2/
// Given two sorted arrays, find their union and intersection.
// Example:

// Input : arr1[] = {1, 3, 4, 5, 7}
//         arr2[] = {2, 3, 5, 6} 
// Output : Union : {1, 2, 3, 4, 5, 6, 7} 
//          Intersection : {3, 5}

// Input : arr1[] = {2, 5, 6}
//         arr2[] = {4, 6, 8, 10} 
// Output : Union : {2, 4, 5, 6, 8, 10} 
//          Intersection : {6}


#include<bits/stdc++.h>
using namespace std;

void printUnion(int arr1[],int arr2[],int n,int m)
{
    int i=0;
    int j=0;

    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            cout<<arr1[i]<<" ";
            i++;
        }
        else if(arr2[j]<arr1[i])
        {
            cout<<arr2[j]<<" ";
            j++;
        }
        else
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }

    while(i<n)
    {
        cout<<arr1[i]<<" ";
        i++;
    }
    while(j<m)
    {
        cout<<arr2[j]<<" ";
        j++;
    }
}

void printIntersection(int arr1[],int arr2[],int m,int n)
{
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else if(arr2[j]<arr1[i])
        {
            j++;
        }
        else
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
        }
    }
}

int main()
{   
    int n=5;
    int m=4;
    int arr1[n];
    int arr2[m];

    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }

    printUnion(arr1,arr2,n,m);
    cout<<endl;
    printIntersection(arr1,arr2,n,m);

}

// Explaination:- To find union of this ques we used merge sort in different way. If the numbers are same, we moved our pointer i and j forward by 1. If ith element 
// is less than jth then we printed ith element and move ith pointer forward by 1.If jth element is less than ith then we printed jth element and move jth pointer forward 
// by 1.
// Now, to find intersection, if ith and jth element is equal we print that element and move both of them forward by 1, If ith element is less than jth, we move i by 1 and 
// if jth element is less than ith, we move j by 1.