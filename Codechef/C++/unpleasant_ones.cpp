#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],b[n],c[n],j=0,p=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]%2)
	        b[j++]=a[i];
	        else
	        c[p++]=a[i];
	    }
	    p--;
	    j--;
	    for(int i=0;i<n;i++)
	    {
	        if(p>=0)
	        cout<<c[p--]<<" ";
	        else
	        cout<<b[j--]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
/*
Input:
2   
3  
3 6 5  
2   
7 6

Output:
5 6 3  
6 7 
*/