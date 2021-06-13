#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{
    vector<ll int> v; // Initialise vector with name v
    ll int a,n;
    cin>>n;             // n denotes total number of potential customers.
    for(int i=0;i<n;i++)
    {
        cin>>a;            // taking the budget of each cutomer and pushing them into vector v
        v.push_back(a);
    }
    sort(v.begin(),v.end());    // sorting the vector
    for(int i=0;i<n;i++)
    v[i]=v[i]*(n-i);            // multiplying each term of vector with the number of possible customer in that price range
    cout<<*max_element(v.begin(),v.end());      // output highest value
}
