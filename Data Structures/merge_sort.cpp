#include<iostream>
#include<vector>
using namespace std;

void merge(int* arr,int l,int m,int h){
    int i = l;
    int j = m+1;
    int b[h];
    int k= l;
    while(i<=m && j<=h){
        if(arr[i]<=arr[j]){
            b[k] = arr[i];
            i++;
        }else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    if(i>m){
        while(j<=h){
            b[k] = arr[j];
            k++;
            j++;
        }
    } else if(j>h){
        while (i<=m){
            b[k] = arr[i];
            i++;
            k++;
        }
    }

    for(int i = l;i<=h;++i){
        arr[i] = b[i];
    }
}

void mergeSort(int* arr,int l,int h){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}



ostream& operator<<(ostream& os,vector<int> arr){
    for(int i = 0;i<arr.size();++i){
        os<<arr[i]<<" ";
    }
    return os;
}



int main(){
    int arr[] = {10,2,20,4,21,12,5,43,2,2,3,5};
    mergeSort(arr,0,11);
    vector<int> vec(arr,arr+12);
    cout<<vec;
    return 0;
}