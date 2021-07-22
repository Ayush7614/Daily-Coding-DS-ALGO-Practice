// Intro: 
// Problem link: https://www.codechef.com/problems/WAV2
// In this question we have to find if the value of the equation will be positive, negative or 0
// We have to check number of negative terms present in the eq. If they are even then eq wiil be +ve else -ve
// If we encounter a root then the eq will be 0
// We have to sort the given root and then find the lower bound of each query
// if the element present at that location is = x then it is a root, output zero
// Otherwise find index of (n - lowerbound) if it is even then the output POSITIVE else output NEGATIVE


#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int n,q,a,x,index,i;
    cin>>n>>q;
    ll int v[n];
    for(i=0;i<n;i++)
    cin>>v[i];
    sort(v,v+n);    // sorting the given array
    while(q--)
    {
        cin>>x;
        a=lower_bound(v,v+n,x)-v;   //finding the index of lowerbound(a)
        index = n-a;                // n - index of lowerbound(a)
        if(v[a]==x)                 // checking if x is a root ot not
        cout<<"0";
        else if(index%2==0  || x>v[n-1])    //Positive is number of negative elements is even or if x is bigger than all the roots
        cout<<"POSITIVE";
        else                                // else Negative
        cout<<"NEGATIVE";
        cout<<"\n";
    }
    return 0;
}

// Sample input/output 

// Example Input
// 4 6
// 1 3 5 100
// -2
// 2
// 4
// 80
// 107
// 5

// Example Output
// POSITIVE
// NEGATIVE
// POSITIVE
// NEGATIVE
// POSITIVE
// 0