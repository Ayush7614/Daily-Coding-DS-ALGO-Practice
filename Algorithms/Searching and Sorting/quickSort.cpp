#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define endl "\n"
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define countsetb(n) __builtin_popcount(n)
#define logarr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<" "


//8
//5 2 0 9 7 1 8 6
//2 5 6 9 7 1 8 0
//2 5 6 7 1 8 0 9

int partition(vi &arr,int lo,int hi) {
	int m = lo;
	int pivot = hi;

	for(int i=lo; i<hi; i++) {
		if(arr[i]<arr[pivot]) {
			swap(arr[m],arr[i]);
			m++;
		}
	}

	swap(arr[m],arr[pivot]);
	return m;
}


int randomPivot(vi &arr,int lo,int hi) {
	int n = rand();
	int pivot = lo + (n%(hi-lo+1));
	swap(arr[pivot],arr[hi]);
	return partition(arr,lo,hi) ;
}


void quicksort(vi &arr,int lo,int hi) {
	if(lo>=hi) {
		return ;
	}
	if(lo<hi) {
		int pivotIndex = randomPivot(arr,lo,hi);
		quicksort(arr,lo,pivotIndex-1);
		quicksort(arr,pivotIndex+1,hi);
	}
	return ;
}

int main() {
	fast_io;

	int n;
	
	cout<<"Enter size of array: ";
	cin>>n;
	
	cout<<"\nEnter elements of araray: \n";
	vi arr(n);
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	cout<<"Array is \n";
	logarr(arr,n);	
	
	quicksort(arr,0,n-1);
	
	cout<<"\nSorted array is \n";
	logarr(arr,n);	

	return 0;
}
