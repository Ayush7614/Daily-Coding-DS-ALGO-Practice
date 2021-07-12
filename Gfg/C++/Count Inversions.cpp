#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void convertt(long long arr[], long long n){
        long long i, temp[n];
        
        for(i=0;i<n;i++){
            temp[i]=arr[i];
        }
        
        sort(temp, temp+n);
        
        for(i=0;i<n;i++){
            arr[i]=lower_bound(temp, temp+n, arr[i]) - temp + 1 ;
        }
    }
    
    long long getSum(long long BIT[], long long idx){
        long long sum=0;
        while(idx > 0){
            sum+=BIT[idx];
            idx-=idx&-idx;
        }
        return sum;
    }
    
    void updateBIT(long long BIT[], long long n, long long idx, long long value){
        while(idx <= n){
            BIT[idx]+=value;
            idx+=idx&-idx;
        }
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        long long i,count=0;
        convertt(arr, n);
        long long BIT[n+1]={0};
        for(i=n-1;i>=0;i--){
            count+=getSum(BIT, arr[i]-1);
            updateBIT(BIT, n, arr[i], 1);
        }
        return count;
}
};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends
