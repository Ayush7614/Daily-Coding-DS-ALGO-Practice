/* 
Given an array arr[] of size n.
The task is to find repeating element in the array of integers, i.e an element that occurs more than once and whose index of first occurence is smallest.

constraints :

1<=n<=10^6
0<=Ai<=10^6

Input :
7

1 5 3 4 3 5 6

Output :
1


5 is appearing twice and its first appearance is at index "1" which is less than 3 whose first occuring index is "2".
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n :";
    cin>>n;
    int arr[n];
    cout<<"Enter elements :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    
    const int N=1e6+2;
    int idx[N];
    for(int i=0;i<N;i++)
    {
        idx[i]=-1;
    }
    
    int minidx=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(idx[arr[i]]!=-1)
        {
            minidx=min(minidx,idx[arr[i]]);
        }
        else
        {
            idx[arr[i]]=i;
        }
    }
    
    minidx==INT_MAX ? cout<<"-1" : cout<<minidx;
    return 0;
}