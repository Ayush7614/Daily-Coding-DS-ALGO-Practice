#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1000000007;

int main()
{
    //t -> No of Test Cases
    ll t; 
    cin>>t;
    while(t--)
    {
     int n,k,x,y;
     cin>>n>>k>>x>>y;

     //Case 1:  If already the ball is at one of the corners, no need of any processing
     if(x==y)
        cout<<n<<" "<<n<<"\n";

    //Case 2: If the ball is not at any corners, instead it lies somewhere on
    //the Billiard Board

     else
     {
         map<int, pair<int,int>>m;
         // Storing the Coordinates inside map
         if(x<y)
         {
             swap(x,y);
             m[1]={y+n-x,n};
             m[2]={n,y+n-x};
             m[3]={x-y,0};
             m[4]={0,x-y};
         }
         else
         {
             m[1]={n, y+n-x};
             m[2]={y+n-x,n};
             m[3]={0,x-y};
             m[4]={x-y,0};  
         }
         ll eff=((k-1)%4)+1;
             cout<<m[eff].first<<" "<<m[eff].second<<"\n";
     }
    }
}