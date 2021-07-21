#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int counterZero=0 , counterOne = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]==0)
	        counterZero++;
	        else
	        counterOne++;
	    }
	   for(int i=0;i<n;i++)
	   {
	       if(counterZero!=0)
	       {
	           cout<<"0";
	           counterZero--;
	       }
	       else if(counterZero==0 && counterOne!=0)
	       {
	           cout<<"1";
	           counterOne--;
	       }
	   }
	   cout<<endl;
	}
	return 0;
}
