#include<iostream>
#include<cmath>
using namespace std;
void bubble_sort(int arr[],int n){
    for(int i =0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        
    }
}
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j =i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;

    }
}
void merge(int arr[],int p ,int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    int l[n1];
    int b[n2];
    for( int i =0;i<n1;i++){
        l[i]=arr[i+p];
    }
    for(int j =0;j<n2;j++){
        b[j]=arr[q+j+1];
    }
    l[n1]=NULL;
    b[n2]=NULL;
    int i,j;
    i=j=0;
    int k;
    for( k =p;k<r;k++){
        if(l[i]<=b[j]){
            arr[k]=l[i];
            i++;
        }
        else{
            arr[k]=b[j];
            j++;
        }
        
    }
    while(i<n1){
        arr[k++]=l[i++];
    }
    while(j<n2){
        arr[k++]=b[j++];
    }
}
void merge_sort(int arr[],int p,int r){
    if(p<r){
        int q=floor((p+r)/2);
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
    
}
void inputarr(int arr[],int n){
    for(int i =0;i<n;i++){
        std::cin>>arr[i];
    }
}
void outputarr(int arr[],int n){
    for(int i =0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    std::cin>>n;
    int arr[n];
    std::cout<<"enter the array";
    inputarr(arr,n);
    //bubble_sort(arr,n);
   // insertion_sort(arr,n);
  // merge_sort(arr,0,n-1);
    outputarr(arr,n);

    return 0;
}