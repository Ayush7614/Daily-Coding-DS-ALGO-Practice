//Problem link: https://www.codechef.com/SDPCB21/problems/QUALPREL

//Solution:

#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int s[n];
	 
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }

	    sort(s,s+n, greater<int>());  //sort the array in descending order
	    int score=s[k-1];  //index started from 0
	    int count=0;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]>=score)
	        {
	            count++;
	        }
	        else
	        break;
	    }
	    cout<<count<<endl;
	    
	}
	return 0;
}

// Test Case:
//INPUT:
//2
//5 1
//3 5 2 4 5
//6 4
//6 5 4 3 2 1

//OUTPUT:
//2
//4

