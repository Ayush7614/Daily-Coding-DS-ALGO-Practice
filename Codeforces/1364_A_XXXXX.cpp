/*
      ok Dividing this simple problem into some cases
        case 1-> If every number is divisible by x then we will print -1 
        Case 2-> If Sum is not divisible by x then we will print n
        Case 3-> Now we have 2 Answer's It can be Either We can take Prefix or we can take suffix elements
    
*/


#include <bits/stdc++.h>

#define ll                  long long
#define en                  '\n'
#define repi(i,n)           for (int i = 0; i <n; i++)


using namespace std;


void solve()
{
        int n;
        cin>>n;
        ll x;
        cin>>x;
        ll cn=0;
        ll su=0;
        vector<int> di;
        ll sudi=0;
      	vector<int> v(n);
      	repi(i,n)
      	{

      		cin>>v[i];
      		if(v[i]%x==0)
      		{
      			cn++;
      			di.pb(v[i]);
      			sudi+=v[i];
      		}
      		su+=v[i];
      	}
      	if(cn==n)
      	{
      		cout<<-1<<en;   // case 1 
      		return;
      	}
      	if(su%x!=0)
      	{
      		cout<<n<<en;  // Case 2
      		return;
      	}
      	

      	// 7 7 7 5 6 7 8 9

  // Case -> 3
  
      	int to=su;
      	int  mini=0;
      	for(int i=0;i<n;i++)    // checking prefix number's which are divisible and removing them
      	{
      		to=to-v[i];

      		if(to%x!=0)
      		{
      			mini=max(mini,n-(i+1));
      			break;
      		}

      	}
      	to=su;
      	for(int i=n-1;i>=0;i--)     // checking Suffix number's which are divisible and removing them 
      	{
      		to=to-v[i];
      		if(to%x!=0)
      		{
      			mini=max(mini,i);
      			break;
      		}

      	}
      	cout<<mini<<en; //Printing Minimum of them 






}


int main(void)
{

       

      ll test_case=1;
      cin>>test_case;
     
      while(test_case--)
      {

        solve();
       
      }
      
  return 0;

}
 
