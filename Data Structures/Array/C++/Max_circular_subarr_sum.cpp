#include <iostream>
#include <climits>
using namespace std;

int kadane(int arr[], int n){
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum < 0){
            currSum = 0;
        }
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int wrapsum;
    int nonwrapsum;
    int totalSum = 0;
    
    nonwrapsum = kadane(arr, n);
    for(int i=0;i<n;i++){
        totalSum += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = totalSum + kadane(arr, n);
    
    cout<<max(wrapsum, nonwrapsum)<<endl;
    return 0;
}