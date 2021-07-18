#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        int w1,w2,x1,x2,m;
        cin>>w1>>w2>>x1>>x2>>m;
        int difference = w2-w1;
        int minRange = x1 * m;
        int maxRange = x2 * m;
        if(difference >= minRange && difference <= maxRange)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0;
}