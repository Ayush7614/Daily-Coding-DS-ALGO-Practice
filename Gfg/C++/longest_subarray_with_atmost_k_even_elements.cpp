// problem link: https://practice.geeksforgeeks.org/problems/longest-subarray-with-atmost-k-even-elements/0/?category[]=sliding-window&category[]=sliding-window&difficulty[]=0&page=1&sortBy=submissions&query=category[]sliding-windowdifficulty[]0page1sortBysubmissionscategory[]sliding-window#
// window sliding technique
#include <iostream>
using namespace std;

int main() {
    int t;
    long int n,k;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>n>>k;
        long int arr[n];
        for(int j=0; j<n; j++)
        {
            cin>>arr[j];
        }
        long int even=0, len=0, max=0, start=0;
        for(int j=0; j<n; j++)
        {
            if(arr[j] % 2 == 0) // in case it is even then calculations need to be considered
            {
                if(even < k) even++; // if even elements are less than k then simply incrementing the tvalue of even variable
                else
                {
                    even++; // else we wait until we get a window which is feasible acc to question
                    while(start < j && even > k)
                    {
                        if(arr[start] % 2 == 0) even--;
                        start++;
                    }
                    
                }
            }
            len=j-start+1; 
            if(len > max) max=len; // to store maximum length of the window
            
        }
        cout<<max<<endl;
    }
	
	return 0;
}
