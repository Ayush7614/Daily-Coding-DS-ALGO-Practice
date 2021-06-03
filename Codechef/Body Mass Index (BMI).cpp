#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	   int h,m;
	   cin>> m >>h;
	   int bmi=m/(h*h);
	   if(bmi<=18)
	   cout<<"1"<<endl;
	   else if(bmi<=24)
	   cout<<"2"<<endl;
	   else if(bmi<=29)
	   cout<<"3"<<endl;
	   else
	   cout<<"4"<<endl;
	}
	return 0;
}
