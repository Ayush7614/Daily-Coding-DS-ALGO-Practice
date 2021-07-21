//         Move All Negative numbers at the beginning
//     Link of the problem: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

// An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

// Examples : 

// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5
// Note: Order of elements is not important here.

#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int shiftAll(int arr[],int l,int r)
{
    while(l<=r)
    {
        if(arr[l]<0 && arr[r]<0)
        {
            l++;
        }
        else if(arr[l]>0 && arr[r]<0)
        {
            swap(arr,l,r);
            l++;
            r--;
        }
        else if(arr[l]>0 && arr[r]>0)
        {
            r--;
        }
        else    //arr[l]<0 && arr[r]>0
        {
            l++;
            r--;
        }
    }
}

int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    shiftAll(arr,0,8);
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}


// Expaination:- In this solution we have two pointers l and r which starts from beginning and end. 
//             Then we put different conditions to print our negative no.at beginning