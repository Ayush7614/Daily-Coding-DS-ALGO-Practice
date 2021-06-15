#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() 
{
    ll int t;
    cin>>t;         //taking input for test cases 
    while(t--)
    {
        string s;   //taking sring input
        cin>>s;
        ll int l,left[26]={0},right[26]={0},temp,ui;
        l=s.length();   //calculate string length
        if(l%2!=0)
        ui=((l/2)+1);
        else            //caluclating the middle element's index number (ui)
        ui=l/2;        
        for(int i=0;i<(l/2);i++)
        {
            temp=s[i];  
            left[temp-97]++;    //calculating occurance of each alphabet on left side of given string
        }        
        for(int i=ui;i<l;i++)
        {
            temp=s[i];
            right[temp-97]++;   //calculating occurance of each alphabet on right side of given string
        }
        for(int i=0;i<26;i++)
        {
            if(left[i]!=right[i])
            {
                temp=0;     
                break;          //comapring both sides 
            }
        }
        if(temp==0)
        cout<<"NO\n";
        else                    //if both sides are equal output = Yes otherwise output = No
        cout<<"YES\n";
    }
}

/*
Sample input/output 

Input:
6
gaga
abcde
rotor
xyzxy
abbaab
ababc


Output:
YES
NO
YES
YES
NO
NO
*/
