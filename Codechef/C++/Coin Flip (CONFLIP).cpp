#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() 
{
    int t;
    cin>>t;       //taking input for test cases 
    while(t--)
    {
        int g;      // g denotes the number of games played by Elephant 
        cin>>g;
        while(g--)
        {
            int n,I,q; 
            // n denotes the number of coins and rounds
            // I = intial state of coin
            // q denotes head(1) or tail(2)       
            cin>>I>>n>>q;
            if(n%2!=0)      // For odd number of n
            {
                if(I==q)
                cout<<n/2<<endl;
                else 
                cout<<((n/2)+1)<<endl;
            }
            else            // For even number of n
            {
                cout<<n/2;
            }
        }
    }
    return 0;
}