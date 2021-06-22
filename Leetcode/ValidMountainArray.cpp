/*Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:
1. arr.length >= 3
2. There exists some i with 0 < i < arr.length - 1 such that:
    a. arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    b. arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Sample test cases:
1. Input: arr = [2,1]
   Output: false
2. Input: arr = [3,5,5]
   Output: false
3. Input: arr = [0,3,2,1]
    Output: true */

#include<bits/stdc++.h>
using namespace std;

bool validMountainArray(vector<int> arr) {
    int l=arr.size();
    int i=0;
    //traversing the ascending part of the mountain
    while((i+1<l) &&(arr[i]<arr[i+1]))
        i++;
    //checking if the peak is the first/last element. In that case it is not a valid mountain array    
    if(i==0 || i==l-1)
        return false;
    //traversing the descending part of the array    
    while(i+1<l && arr[i]>arr[i+1])
        i++;
    if(i==l-1)
        return true;
    else
        return false;
}

int main(){
    vector<int> arr;
    int n;
    while(cin>>n){
        arr.push_back(n);
    }
    if(validMountainArray(arr))
    cout<<"true";
    else
    cout<<"false";
    
}