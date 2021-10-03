// https://www.codechef.com/COOK133B/problems/FAKESWAP


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long int ulli;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tc ll t;cin>>t;while(t--)


void solve(){
    int n,flag=0,x=0,y=0;
    cin>>n;
    string s,p;
    cin>>s>>p;

    for(int i=0;i<n;i++){
        if(s[i] != p[i]){     // this loop check if both string s are d/f or same
            flag = 1;     
            break;
            }
    }
    if(!flag) {          // if strings are same than ans would be "YES"
        cout<<"YES"; return;    
        }
    for(char c:p){
        if(c=='1') x++; // count number of 1s
        else y++;       // count number of 0s
        if(x>0 && y>0) { // check if string is not all 0's or all 1's.. bcoz if string contain only 0's or only 1's ans would be "NO"
                          // It is impossible to convert SS into PP only when SS != PP and PP is either all 0s0s or all 1s1s.
            cout<<"YES"; 
            return;
            }
    }
    cout<<"NO";
    return;
    
}

int main(){
    fastio

    tc{
       solve();
       cout<<'\n';

    }
    

    return 0;
}