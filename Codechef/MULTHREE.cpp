// Intro:
// Problem link: https://www.codechef.com/LRNDSA01/problems/MULTHREE

// Construction of number:
// 1st term = d0
// 2nd term = d1
// 3rd term(d2) = (d0+d1)%10
// 4th term(d3) = (d0+d1+d2)%10 which can be written as (2(d0+d1))%10
// 5th term(d4) = (3(d0+d1))%10
// .
// .
// kth term (dk) = 2^(k-2)(d0+d1)%10

// Condition of divisibility:
// For a number to be divisible by 3 the sum of individual digit should be divisible by 3
// i.e. (d0+d1+d2+d3+....+dk)%3 == 0

// Since the constraints of the given problem is large therefore we cannot simply find the sum of all digit and then check if it is divisible by 3 or not
// In this case every 4th value repeats itself(counting from the 4th term)
// Therfore we have to find how many such cycles exist and then add the leftover digits

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll int k,d0,d1,sum=0,s,cvalue,cycles,left,lvalue=0,temp;
    cin>>k>>d0>>d1;
    s=d0+d1;
    if(k==2)
    sum=s;
    else
    {
        cvalue = ((2*s)%10) + ((4*s)%10) + ((8*s)%10) + ((6*s)%10);         //calculating value of a single cycle 
        cycles=(k-3)/4;                                                     //calculating number of cycles
        left = (k-3)%4;                                                     //calculating leftover digits
        temp=2;                                                                     
        while(left--)
        {
            lvalue = lvalue + (temp*s)%10;
            temp = (temp*2)%10;                                            //calculating the total of leftover digits
        }
        sum = s + s%10 + cycles*cvalue + lvalue;                           //Sum = first two digits + 3rd digit + no. of cycles*their frequency + leftover digits
    }
    if(sum%3==0)                                                           // check if sum of all digits is divisible by 3 or not 
    cout<<"YES";
    else 
    cout<<"NO";
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

// Sample input/output

// Input:
// 3
// 5 3 4
// 13 8 1
// 760399384224 5 1

// Output:
// NO
// YES
// YES