// Intro:
// Problem link: https://www.codechef.com/COOK130C/problems/BALLOON
// We have to find the minimum number of elements in an array in which all the numbers from 1-7 are present
// We can start from index 7 since total number required are 1 - 7 therefore minimum 7 problems chef has to solve no matter what
// We check from index 7 - n and find out if any number between 1-7 are present or not, if yes then output that value

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll int t;
    cin>>t;
    while(t--)
    {
        int n,a,max;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            v.push_back(a);         
        }
        max = 6;                //minimum index in any condition
        for(int i=7;i<n;i++)
        {
            if(v[i]<8)
            max=i;              //If number between 1-7 exist then change the index value
        }
        cout<<" = "<<(max+1)<<endl;  //Since indexing starts from zero therefore max+1
    }
}

// Sample input/output:

// Example Input
// 3
// 7
// 1 2 3 4 5 7 6
// 8
// 8 7 6 5 4 3 2 1
// 9
// 7 4 3 5 6 1 8 2 9

// Example Output
// 7
// 8
// 8