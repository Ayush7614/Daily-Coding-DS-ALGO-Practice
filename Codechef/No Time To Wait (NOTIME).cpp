#include<iostream>
using namespace std;

int main()
{
    int n,h,x;
    cin>> n >> h >>x;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    bool ans=0;
    for(int j=0;j<n;j++)
    {
        if(x + arr[j]==h)
        {
            ans=1;
            break;
        }
    }
    if(ans==1)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    
    return 0;
}
