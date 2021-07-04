/*
CODE DESCRIPTION:
A peak element is an element which is greater than its neighbours.

Here we are given an array , we need to find a peak element, and return its index.
If the array contains multiple peaks, return the index to any of the peaks.
*/

#include<iostream>
using namespace std;

/* function which return index of peak element */
int find_peak(int a[],int n){

    /* loop from i=0 to i=(size of array - 1) */
    for(int i=0;i<n;i++){

        /* if 1st element is peak element */
        if(i==0 && a[i]>a[i+1])
        return i;

        /* if last element is peak element */
        else if(i==n-1 && a[i]>a[i-1])
        return i;
        
        /* if element other than 1st and last elemnt is peak element */
        else if(a[i]>a[i+1] && a[i]>a[i-1])
        return i;
    }

    /* if all elemnts in array are same */
    return -1;
}

int main(){
    int i,n,count=0;

    /* ask user input */
    cout<<"Enter no. of elemnts in array: ";
    cin>>n;

    /* intialize an array of size n */
    int a[n];

    /* ask user input */
    cout<<"Enter array elements: ";
    for(i=0;i<n;i++)
    cin>>a[i];
    
    /*print index of peak element */
    int pos = find_peak(a,n);
    if(pos!=-1)
    cout<<"Peak element index is: "<<pos;
    else
    cout<<"All elements are same hence no peak value found!!!";
    
    return 0;
}

/*
Time complexity: O(n). 
Space Complexity: O(1). 

OUTPUT:
Enter no. of elemnts in array: 7
Enter array elements: 10 20 15 2 23 90 67
peak element index is: 1
*/