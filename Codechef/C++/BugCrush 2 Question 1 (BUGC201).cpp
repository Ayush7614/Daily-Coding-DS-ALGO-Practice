#include<bits/stdc++.h>
using namespace std;
#define bruh main
int bruh(){
int n;
cin>>n;
vector<int>v;
int input;
for(int i=0;i<=n;i++)
{
	cin>>input;
	v.push_back(input);
}
sort(v.begin(),v.end());
cout<<v[n]+v[n-1]<<endl;
return 0;
}