//Find the "Kth" max and min element of an array 
#include<bits/stdc++.h>
using namespace std;
int main(void){
    
    int n;
    cout<<"Enter the number of elements array will contain: ";
    cin>>n;//input of the number of element in an array
    cout<<endl;
    
    int k;
    cout<<"Enter the kth maximum/minimum term you want to find: ";
    cin>>k;//input of the kth maximim/minimum term you need to find 
    cout<<endl;
    
    int arr[n];//initializing an array
    cout<<"Input the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];//input of the element in the array
    }
    //sortinng the array by any of the one methods ... insertion sort , bubble sort or selection sort
    //insertion sort method 
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int j=i-1;
        while(arr[j]>curr&&j>=0){
            arr[j+1]=arr[j];
            j--;//decrement of j by 1 digit 
        }
        //cause of decrement of j in while we are writing j+1
        arr[j+1]=curr;
    }
    //printing the array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    choice_selection:
        int choice;
        cout<<"Enter your choice(Press 1 for maximum kth element or press 2 to get the minimum kth element):   ";
        cin >> choice;
        cout <<endl;
        if(choice==1)
        {
            cout<<endl;
            //finding the kth maximum number 
            for(int i=0,j=n-1;i<=j;i++,j--)
            {
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            
            cout<<"Kth maximum term is:-"<<arr[k-1]<<endl;
        }
        else if(choice==2)
        {
            cout<<endl;
            //finding the kth minimum number 
            cout<<"Kth minimum term is:-"<<arr[k-1]<<endl;
        }
        
        else 
        {
            cout <<"Please enter valid number.";
            cout<<endl;
            goto choice_selection;
            
        }
    return 0;
    
    
}