#include<iostream>
#include<vector>
using namespace std;


void swap(int& a,int& b){
    a = a^ b;
    b = a^ b;
    a = a^ b;
}


int partition(int* arr, int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while(start<end){
        while (arr[start]<=pivot){
            start++;
        }
        while (arr[end]>pivot){
            end--;
        }
        if(start<end)
        swap(arr[start],arr[end]);   
    }

    swap(arr[end],arr[lb]);
    return end;
}
 
void quickSort(int* arr, int lb, int ub){

    if(lb<ub){
        int pivot = partition(arr,lb,ub);
        quickSort(arr,lb,pivot-1);
        quickSort(arr,pivot+1,ub);
    }
}


ostream& operator<<(ostream& os,vector<int> arr){
    // int size = my_sizeof(arr)/my_sizeof(arr[0]);
    for(int i = 0;i<arr.size();++i){
        os<<arr[i]<<" ";
    }

    return os;
}



int main(){
    int arr[] = {10,2,20,4,21,12,5,43,2,2,3,5};
    quickSort(arr,0,11);
    vector<int> vec(arr,arr+12);
    cout<<vec;
    return 0;
}