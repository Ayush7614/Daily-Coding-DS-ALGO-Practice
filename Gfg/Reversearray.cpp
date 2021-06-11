#include <iostream>
using namespace std;

int main() {
     int t;
     cin>>t;
     // test cases
     while(t--)  
     {
         int n;
         cin>>n;
         int arr[n];
         // array as input
         for(int i = 0; i < n; i++)
          cin>>arr[i];
          
          // array reversed
          for(int i = n-1; i >= 0; i--)
           cout<<arr[i]<<" ";
           
           cout<<endl;
     }
	return 0;
}