#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long int t;
	cin>>t;
	while(t--){
	    long int m,x,d, n,k, start = 0, end = 0;
	    cin>>n>>m;
	    long int arr[m], freq[n];
	    for(long int i=0;i<n;i++){
	        freq[i]=0;
	    }
	    for(long int i=0;i<m;i++){
	        cin>>arr[i];
	        freq[arr[i]-1]+=1;
	    }
	    long int ans = m;
	    while(start<=end && end<m){
	        long int item = arr[end++];
	        freq[item-1]--;
	        while(start<end && freq[item-1]==0){
	           freq[arr[start++]-1]++;
	        }
	        if(freq[item-1]!=0){
	            ans = min(ans, m-(end-start));
	        }    
	        
	    }
	    cout<<ans<<"\n";
	}
	return 0;
}

//sample input
// 3
// 2 2
// 1 2
// 2 3
// 1 2 1
// 3 6
// 1 1 1 3 2 2

//sample output
// 2
// 2
// 4

