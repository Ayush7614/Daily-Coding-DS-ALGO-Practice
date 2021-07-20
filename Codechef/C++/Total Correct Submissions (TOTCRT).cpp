// Intro:
// Problem link: https://www.codechef.com/problems/TOTCRT
// In this question we have to create a hash map, map(string -> integer)
// String (problem code) denotes the index and we have to check and insert the int value accordingly
// Once all the values are inserted in the map, iterate through it and copy the integer value to a vector 
// sort the vector and display it

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    map<string,int> mp;             //defining map
    string s;
    int n,x;
    cin>>n;
    for(int i=0;i<3*n;i++)
    {
        cin>>s>>x;                  // taking input of problem code and number of solutions
        mp[s]+=x;                   // transfer the value to the map 
    }
    vector<int> ans;
    map<string,int>::iterator itr;
    for (itr = mp.begin(); itr != mp.end(); ++itr) 
    ans.push_back(itr->second);     //tranfer the int value to a vector
    sort(ans.begin(),ans.end());    //sort the vector
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";              //output the vector
    cout<<"\n";
}
int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

// Sample Input/Output


// Example Input
// 3
// 1
// A 1
// B 2
// C 3
// 2
// AA 1
// AB 1
// AB 1
// AC 1
// AC 1
// AD 1
// 1
// Z 100
// Z 100
// Z 100


// Example Output
// 1 2 3
// 1 1 2 2
// 300