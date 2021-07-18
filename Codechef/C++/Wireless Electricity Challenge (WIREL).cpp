#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int x[n],y[n];
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    int a[n],b[n],c[n],d[n];
    for(int i=0;i<m;i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(int i=0;i<m;i++)
    {
        if(a[i]>c[i])
        {
            swap(a[i],c[i]);
            swap(b[i],d[i]);
        }
        if(i%2==0)
        {
            cout<<-a[i]<<" "<<-b[i]-1<<endl;
        }
        else
        {
            cout<<1000000+1-a[i]<<" "<<1000000-b[i]<<endl;
        }
    }
        
        	



	return 0;
}
