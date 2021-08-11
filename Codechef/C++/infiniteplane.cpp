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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        map<int, int> v;
        int c =0 ;
        for (int i = 0; i < n; i++)
        {
            if(v.find(a[i])==v.end()) 
            {
               v[a[i]]++;
               c++;
            }
            else
            {
                if(v[a[i]]<a[i]-1)
                {
                    c++;
                    v[a[i]]++;
                }
            }
        }
        cout<<c<<endl;        
    }
    return 0;
}