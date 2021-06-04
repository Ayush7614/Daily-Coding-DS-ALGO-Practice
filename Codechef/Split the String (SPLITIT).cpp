#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        string s;
        cin>> n >>s;
        char last=s[n-1];
        bool ans=0;
        for(int i=0;i<n-1;i++)
        {
            if(last==s[i])
            {
                ans=1;
                break;
            }
        }
        if(ans==1)
        cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    }
    return 0;
}