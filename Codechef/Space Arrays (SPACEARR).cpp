#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        sort(arr,arr+n);
        int val=0,flag=0;
        
        for(int i=0;i<n;i++)
        {
            if(i + 1 - arr[i] < 0)
            {
                flag=1;
                break;
            }
        val = val + (i+1-arr[i]);    
        }
        
        if(flag==1)
        cout<<"Second"<<endl;
        else
        {
            if(val % 2 ==1)
            {
                cout<<"First"<<endl;
            }
            else
            cout<<"Second"<<endl;
        }
        
    }
    
    return 0;
}