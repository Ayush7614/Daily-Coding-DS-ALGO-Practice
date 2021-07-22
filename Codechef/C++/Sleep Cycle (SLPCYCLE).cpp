// Intro:
// In this question we have to find out if chef can complete his sleep cycle or not
// According to given condition if chef is not able to sleep h units of time in a single attempt then the remaing time will be 2(h-x)
// We have to finds the block of zeros present in a given string and check is chef can sleep in that block or not/
// one thing to keep in mind here is chef will not sleep for every '0' present in the given string.
// Chef will only sleep if 2(h-x)<h otherwise the total time will increase
// Define a vector zeros which store the blocks of zeros present in a string.
// Itterate through the vector and decide if the chef will sleep in that block of time or not.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int h,l,c=0;
    string s;
    cin>>l>>h>>s;
    vector<int> zeros;              //vector to store the number of continuous zeros present in the string
    zeros.push_back(0);             //initializing 
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0')
        c++;
        else
        {
            if(c>0)
            zeros.push_back(c);     // storing blocks of zeros
            c=0;
        }
    }
    if(c>0)
    zeros.push_back(c);            // storing the ending block if present 
    for(int i=1;i<zeros.size();i++)
    {
        if(zeros[i]>=h)             //if x>=h 
        {
            h=0;
            break;
        }
        if(h>(2*(h-zeros[i])))      // if h>2*(h-x) chef will sleep in that duration 
        h=2*(h-zeros[i]);
    }
    if(h==0)                        //if chef can complete his sleep cycle the output 'yes' else 'no'
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

// Test cases:

// Example Input
// 4
// 3 1
// 111
// 3 1
// 101
// 7 5
// 0000100
// 6 5
// 000010

// Example Output
// NO
// YES
// YES
// NO