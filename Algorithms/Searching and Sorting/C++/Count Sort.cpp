/* Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). */

#include <bits/stdc++.h>
using namespace std;

int findMax(int A[],int n){     //to find and return the maximum element of array

    int max=-32768;

    for(int i=0;i<n;i++){
        if(A[i]>max) max=A[i];
    }

    return max;
}

/* Count Sort */

void countSort(int A[],int n){           

    int m,i,j,k;
    m=findMax(A,n);       //to store the value of maximum element in array

    int *C;               //creating a temporary array dynamically of size max+1
    C=new int[m+1];     
    
    //initialising the array with 0 initially
    for(i=0;i<=m;i++){
        C[i]=0;
    }
    
    //increasing the index where index = value of element in given array
    for(i=0;i<n;i++){
        C[A[i]]++;
    }

    j=0;
    
    //run the loop to traverse the temporary array filled (to sort the elements)
    for(i=0;i<=m;i++){

        while(C[i]!=0){     //proceed till the value at index i is not 0
            A[j]=i;         //fill the given array again in a sorted manner
            j++;            //increment j to move it to next location
            C[i]--;         //decrease the value we store in temporary array as we've filled it in sorted array
        }

    }
    
    //displaying the sorted array
    for(k=0;k<n;k++){
        cout<<A[k]<<" ";
    }
}

/* Driver Code */
int main(){
    int arr[]={8,5,7,3,2,7,6,5,4,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<"\nCount Sort: ";
    countSort(arr,n);

    return 0;
}
