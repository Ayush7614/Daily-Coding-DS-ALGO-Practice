#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter Number ";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==1||i==j)
            cout<<"*";
            else 
            cout<<" ";
        }
        for(int k=n;k>=1;k--)
        {
            if(k==1||k==i)
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==1||i==j)
            cout<<"*";
            else 
            cout<<" ";
        }
        for(int k=n;k>=1;k--)
        {
            if(k==1||k==i)
            cout<<"*";
            else
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
