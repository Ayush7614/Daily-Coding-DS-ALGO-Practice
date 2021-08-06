#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	   long long int n,rev=0;
	   cin>>n;
	   while(n>0)
	   {
	       int x=n%10;
	       rev=rev*10 + x;
	       n=n/10;
	   }
	   cout<<rev<<endl;
	}
	
	return 0;
}
