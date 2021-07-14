
#include<bits/stdc++.h>

using namespace std;


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n)
    {
        // Code here
        int sum=0;
        int left[n];
        int right[n];
        
        left[0]=arr[0];
        for(int i=1; i<n; i++)
        {
            left[i]=max(left[i-1],arr[i]);
        }
        
        right[n-1]=arr[n-1];
        for(int j=n-2; j>=0; j--)
        {
            right[j]=max(right[j+1],arr[j]);
        }
        
        for(int k=0; k<n; k++)
        {
            sum+=min(left[k],right[k])-arr[k];
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}

//code by baljeet-singh97
