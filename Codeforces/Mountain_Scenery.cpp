// question link: https://codeforces.com/contest/218/problem/A
#include <iostream>
using namespace std;
int arr[105];

int main() {
int n,k;
cin>>n>>k;
int max=0;
int nodes=(n*2)+1;
for(int i=0;i<nodes;i++){
	cin>>arr[i];
	if(arr[i]>max)
	max=arr[i];
}

for(int i=0;i<nodes;i++){
	
	if(i%2==1&&k&&(arr[i]-1)>arr[i-1]&&(arr[i]-1)>arr[i+1]){
		arr[i]-=1;
		--k;
	}
}

for(int i=0;i<nodes;i++){
	cout<<arr[i]<<" ";
}
cout<<"\n";

return 0;
}

// Test case 1
// i/p
// 3 2
// 0 5 3 5 1 5 2
// o/p
// 0 5 3 4 1 4 2 

// Test case 1
// i/p
// 1 1
// 0 2 0
// o/p
// 0 1 0 

