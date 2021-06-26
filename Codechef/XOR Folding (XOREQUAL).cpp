// Intro:
// problem link: https://www.codechef.com/problems/XORFOLD

// In this question we have to find whether the final 1x1 grid has value 1 or 0
// if the final value is 1 the output YES or else output NO

// The following is the truth table of XOR:

// 0 ^ 0 = 0
// 0 ^ 1 = 1
// 1 ^ 0 = 1
// 1 ^ 1 = 0

// from the above table we can conclude that the output is 0 if the both the inputs are same
// we can see one more pattern from the table that 1 ^ 1 = 0 and (1 ^ 1) ^ 1 = 1
// from above example we can conclude if 1 is XORed even times then the output is 0 else 1

// In this question we simply have to find the number of ones
// if no. of ones is odd then the output will be 1 (YES)
// else if no. of ones is even then the output will be 0 (NO)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll int t;
    cin>>t;                                     // taking input for test cases 
    while(t--)
    {
        ll int n,m,ones=0;
        cin>>n>>m;                              // n x m represents the grid size
        string s[n];
        for(int i=0;i<n;i++)
        cin>>s[i];                              // taking string input for each row
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<s[i].size();j++)      // iterate through each element of the string and find out the number of ones
            if(s[i][j]=='1')        
            ones++;                             
        }
        if(ones%2!=0)                           // if no. of ones is odd output YES
        cout<<"YES"<<endl;
        else                                    // if no. of ones is even output NO
        cout<<"NO"<<endl;
    }
}

// Sample test cases:

// Example Input
// 2
// 1 2
// 01
// 3 3
// 000
// 111
// 010

// Example Output

// YES
// NO