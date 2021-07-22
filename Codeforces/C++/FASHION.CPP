#include <iostream>
using namespace std;

    void sort(int n,int a[])
    {
      for(int i=0;i<n-1;i++)
      {for(int j=0;j<n-i-1;j++)
      {
          if(a[j]>a[j+1])
          {
              int t=a[j];
          a[j]=a[j+1];
          a[j+1]=t;
          }
      }
      }
    }
    int main()
{
    long long int  t,n,s,m;
    cin>>t;
    int a[n],b[n];
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
           cin>> a[i];
          
        }
          for(int i=0;i<n;i++)
        {
           
           cin>>b[i];
        }
        int s=0;
        sort(n,a);
        sort(n,b);
        for(int j=0;j<n;j++)
        {
           s+=a[j]*b[j];
            }
        cout<<s<<endl;
    }
return 0;

}