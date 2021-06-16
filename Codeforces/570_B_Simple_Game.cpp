/*  so firstly finding which variant is interesting  For Andrew is no need a variant wherein |a - m| > 1 
    because we can increase probability of victory if we will be closer to m
    Then we will be considering two Cases  
    Case 1 : a = c - 1 
    Case 2 : a = c + 1
    
    So Probability of victory will be c / n for first variant and (n - c + 1) / n for second.
     
     And Don't Forget to create a different Case for n=1
*/



#include <bits/stdc++.h>
#define ll                  long long
#define llu                 long long unsigned int


using namespace std;


int main(void)
{
       ll n,m;
        cin>>n>>m;

        ll n1=m-1;
        ll n2=m+1;
        n2=n-n2;
        if(n==1)
        {
            cout<<1<<en;
            return 0;
        }
        if(n2>=n1)
        {
            cout<<m+1<<en;
            return 0;
        }
        cout<<m-1<<en;

  return 0;

}
 
