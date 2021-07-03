#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s) 
{
   long long i=0,k=0,sign=0,n=0;
     for(i=0;i<s.length();i++)
     {
        if(s[i]==' ')
           continue;
        if(s[i]>='0' && s[i]<='9')
            break;
        if(s[i]=='-')
            sign=1;
         k++;
     }
        if(k>1)
            return 0;
        if(k==1 && s[i-1]!='+' &&s[i-1]!='-')
            return 0;
        for(long long j=i;j<s.length();j++)
        {
            if(s[j]<'0' || s[j]>'9')
                break;
            n=n*10+(s[j]-'0');
            
        if(n>=INT_MAX)
            break;
        }
  
        if(sign==1)
            n*=-1;
        if(n<INT_MIN)
            return INT_MIN;
        if(n>INT_MAX)
            return INT_MAX;
        return n;
 }

int main()
{
    cout<<myAtoi("90");
    return 0;
}
/*
Input :- "90"
Output :- 90
*/

