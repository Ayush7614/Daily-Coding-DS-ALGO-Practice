#include <iostream>
using namespace std;

void sievePrimeFactor(int n)
{
    int arr[n+1]={0};
    for(int i=2;i<=n;i++)
    arr[i]=i;
    for(int i=2;i*i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(arr[j]==j)
            {
                if(j%i==0)
                arr[j]=i;
            }
        }
    }
    
    while(n!=1)
    {
        cout<<arr[n]<<" ";
        n=n/arr[n];
    }
}
int main()
{
    int n=20;
    sievePrimeFactor(n);
}
