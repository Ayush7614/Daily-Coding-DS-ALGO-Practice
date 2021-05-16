using namespace std;

int kadane(int *arr,int n){
    
    int max_global,max_current;
    max_global=max_current=arr[0];
    
    for(int i=1; i<n; i++){
        
        max_current = max(arr[i], max_current+arr[i]);
        
        if(max_current>max_global){
            max_global = max_current;
        }
    }
    return max_global;
    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    
	    cout<<kadane(arr,n)<<"\n";
	}
	return 0;
}
