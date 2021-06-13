#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	while(n--)
	{
	    string s;
	    cin>>s;
	    int r=s.size();
	    string a , b;
	    a=s.substr(0,r/2);
	    if(r%2==0)
	    {
	        b=s.substr(r/2, r/2);
	    }
	    else
	    {
	        b=s.substr((r/2)+1, r/2);
	    }
	    
           sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            
            if(a==b)
            {
                cout<<"YES";
            }
            else
            cout<<"NO";
       cout<<endl;
	}
	return 0;
}
