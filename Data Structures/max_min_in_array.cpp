#include<iostream>
#include<climits>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    int arr[size];
    for(int i=0; i<size;i++){
        cin>>arr[i];
    }

    int maxNo = INT_MIN, minNo=INT_MAX;

    for(int i=0; i<size;i++){
        if(arr[i]>maxNo){
            maxNo = arr[i];
        }
        if(arr[i]<minNo){
            minNo = arr[i];
        }
    }
    cout<<"The max element is: "<<maxNo<<endl;
    cout<<"The min element is: "<<minNo<<endl;
    return 0;
}