#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<(b);i++)
#define ff first
#define ss second
#define vi vector<int>


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()!=s2.length())
        cout<<"NO"<<endl;
    else
    {
        ll count =0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
                count++;
            if(count>2)
                break;
        }
        if(count!=2)
            cout<<"NO"<<endl;
        else
        {
            ll first,second;
            bool check1=false,check2=false;
            for(int i=0;i<s1.length();i++)
            {
                if(s1[i]!=s2[i] && check1==false)
                {
                    first=i;
                    check1=true;
                }
                else if(s1[i]!=s2[i] && check2==false)
                {
                    second=i;
                    check2=true;
                }
                if(check1 && check2)
                    break;
                 
                
            }
            swap(s1[first],s1[second]);
            if(s1==s2)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        
        
        
    }
    
    
    
    return 0;
}