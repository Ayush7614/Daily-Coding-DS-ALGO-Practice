//---------Letters---------//

//Problem Link: https://codeforces.com/contest/978/problem/C

/* 
Problem Statement:
There are n dormitories in Berland State University, they are numbered with integers from 1 to n.
Each dormitory consists of rooms, there are ai rooms in i-th dormitory. The rooms in i-th dormitory 
are numbered from 1 to ai.

A postman delivers letters. Sometimes there is no specific dormitory and room number in it on an 
envelope. Instead of it only a room number among all rooms of all n dormitories is written on an 
envelope. In this case, assume that all the rooms are numbered from 1 to a1+a2+⋯+an and the rooms 
of the first dormitory go first, the rooms of the second dormitory go after them and so on.

For example, in case n=2, a1=3 and a2=5 an envelope can have any integer from 1 to 8 written on it.
If the number 7 is written on an envelope, it means that the letter should be delivered to the room
number 4 of the second dormitory.

For each of m letters by the room number among all n dormitories, determine the particular dormitory
and the room number in a dormitory where this letter should be delivered.
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
  ll n,m,x;
  cin>>n>>m;
  ll a[n];

  vector <ll> pre(n,0);
  cin>>a[0];

  pre[0]=a[0];
  for(ll i=1;i<n;i++)
  {
      cin>>a[i];
      pre[i]=pre[i-1]+a[i];
  }
 
  for(ll j=0;j<m;j++)
  {
      cin>>x;
     auto it=lower_bound(pre.begin(),pre.end(),x);

     if(*it==x && (it-pre.begin())==0)
     { 
         ll p=it-pre.begin();
         cout<<p+1<<" "<<*it<<"\n";
     }

     else if(*it==x)
     {
         ll p=it-pre.begin();
         auto it1=it;
         it1--;
         cout<<p+1<<" "<<(*it)-(*it1)<<"\n";
     }

     else
     { 
         ll p=it-pre.begin();
         ll ans=x;
         cout<<p+1<<" ";
         
         if(p!=0)
            ans-=(*(--it));
         cout<<ans<<"\n";
     }
  }
}