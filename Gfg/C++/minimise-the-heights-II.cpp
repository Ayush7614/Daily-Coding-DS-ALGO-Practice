// Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing 
// them by K only once. After modifying, height should be a non-negative integer. 
// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.
//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1


// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        int minele, maxele;
        int result = arr[n - 1] - arr[0];
        for( int i = 1; i < n; i++){
            if(arr[i] >= k && arr[n - 1]>=k){
                maxele = max( arr[i - 1] + k, arr[ n - 1] - k);
                minele = min( arr[0] + k, arr[i] - k);
                result = min( result, maxele - minele);
            }
        }
    return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends