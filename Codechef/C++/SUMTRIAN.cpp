#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
long int n;
while(t--)
{
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<i;j++)
        {
            a[i-1][j]+=max(a[i][j],a[i][j+1]);
        }
    }
    cout<<a[0][0]<<endl;
}
	return 0;
}