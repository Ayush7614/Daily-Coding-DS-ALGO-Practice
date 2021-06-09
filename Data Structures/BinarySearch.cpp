#include<iostream>
using namespace std;

int binarySearch(int* arr, int low, int high,int x){
	int mid = (low + high)/2;
	if(arr[mid] == x){
		return mid;
	} else if (arr[mid]>x){
		return binarySearch(arr,low,mid-1,x);
	}
	return binarySearch(arr,mid+1,high,x);
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,15,19,20,100};
	int s;
	cin>>s;
	cout<<binarySearch(arr,0,16,s);
	return 0;
}
