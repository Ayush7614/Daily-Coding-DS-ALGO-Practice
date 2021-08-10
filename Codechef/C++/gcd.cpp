//question link - https://www.codechef.com/COOK131B/problems/CHFGCD

#include<bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2) 
{
    if (n2 != 0)
        return gcd(n2, n1 % n2);
    else
        return n1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(gcd(x,y)>1)
        cout<<"0"<<endl;
        else if(gcd(x+1,y)>1) 
        cout<<"1"<<endl;
        else if(gcd(x,y+1)>1)
        cout<<"1"<<endl;
        else
        cout<<"2"<<endl;;
    }
    return 0;
}