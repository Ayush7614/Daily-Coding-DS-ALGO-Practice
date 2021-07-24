// problem link: https://www.codechef.com/START6C/problems/THREDICE
// The third person will win only if he can get a number that is strictly greater than the sum of the other two numbers. We have to find the probability of that.
// Let the first person gets the value a and second person gets b.
// The probability of 3rd person winning wiil be 0 if the sum of a and b is greater than or equal to 6 since he cannot get any number greater than 6 in a dice.
// To find the probability we have to find the possible numbers that he can get(6-a+b) and divide it by 6(since there are total of 6 numbers on a dice).

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int a,b;
    double sum;                     // sum is taken as double since the output is a decimal value
    cin>>a>>b;
    sum=a+b;
    if(sum<6)
    cout<<(6-sum)/6<<"\n";          // Poosible numers than can get 3rd person a win / 6
    else
    cout<<"0\n";
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

// Sample input/output 

// Sample Input 1 
// 3
// 1 3
// 2 4
// 2 3

// Sample Output 1 
// 0.333333
// 0
// 0.166666