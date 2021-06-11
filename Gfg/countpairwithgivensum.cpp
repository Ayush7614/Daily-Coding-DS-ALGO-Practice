#include<bits/stdc++.h>
using namespace std;
















/* ******* Your Functions Above ******** */

int main()
{
   
  int n,k;
  cin>>n>>k;
  int arr[n];
  unordered_map<int,int>m;
  int c=0;
  f(i,0,n)
  {
    cin>>arr[i];
  }
  f(i,0,n)
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
    