#include<bits/stdc++.h>
using namespace std;
#define ll long long int
 
 
int main(){
    ll t;
	cin>>t;
    while(t--){
        int n,m,k,c=0,x;
        cin>>n>>m>>k;
        map<int,int> mp;
        vector<int> v1;
        // set<int> s;
        for(int i=0;i<k;i++){
            cin>>x;
            mp[x]++;
        }
        for(auto i:mp){
            if(i.second>1 && i.first<=n){
                v1.push_back(i.first);
            }
        }
        cout<<v1.size()<<" ";
        for(int i=0;i<v1.size();i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
    }
return 0;
}


//sample input
// 3
// 1 1 1
// 1
// 1 1 2
// 1 1
// 5 5 10
// 2 5 2 5 2 4 10 10 10 10


//sample output
// 0
// 1 1
// 2 2 5

