#include<bits/stdc++.h>
using namespace std;

int main()
{

  int n,k;
  cin>>n>>k;
  int arr[n];
  unordered_map<int,int>m;
  int c=0;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  for(int i=0;i<n;i++)
  {
     int x=k-arr[i];
    if(m[x]==0)
    {
      m[arr[i]]++;

    }
    else
    {
      c+=m[x];
      m[arr[i]]++;
    }

  }
  cout<<c<<endl;
  return 0;
  }