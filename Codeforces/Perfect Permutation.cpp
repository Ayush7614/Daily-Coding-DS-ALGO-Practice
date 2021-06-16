#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<=(b);i++)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    if(n%2!=0)
        cout<<-1<<endl;
    else{
        
        int arr[n+1];
        loop(i,1,n)
            arr[i]=i;
        for(int i=1;i<=n;i+=2)
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        loop(i,1,n)
            cout<<arr[i]<<" ";
            
    }
    cout<<endl;
    
    
    
    return 0;
}