#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n){
	for(int i=0;i<n-1;++i){
		for(int j=i+1;j<n;++j){
			if(arr[i]>arr[j]){
				arr[i] =arr[i]^arr[j];
				arr[j] =arr[i]^arr[j];
				arr[i] =arr[i]^arr[j];
			}
		}
	}
}


int main(){

	int arr[] = {1,2,5,4,3,7,6};
	bubbleSort(arr,7);
	
	for(int i=0;i<7;++i){
	cout<<arr[i]<<" ";
	}
	return 0;
	}

