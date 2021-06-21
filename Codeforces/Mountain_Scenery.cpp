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