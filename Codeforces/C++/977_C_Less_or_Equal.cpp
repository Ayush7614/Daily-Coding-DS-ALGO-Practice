/* 
    Case 1 : If We have only One Element Present in Array then we will make Ans as v[0]-1
    case 2 : otherwise we will make ans as V[x]-1;
    
    After this we need to  sort elements in ascending order and then count elements which are less than or equal to our ans
    
    now if cn!=x || ans<1 then we will print -1
    else our ans will be printed 

*/



#include <bits/stdc++.h>
#define ll                  long long

#define en                  '\n'
#define repi(i,n)           for (int i = 0; i <n; i++)

using namespace std;





int main(void)
{

    ll n,x;
   cin>>n>>x;

   vector<int>v(n);
   repi(i,n)
   {
    cin>>v[i];
   }

   sort(v.begin(),v.end());
   ll ans=0;
   if(x==0)
   {
  
      ans=v[0]-1;
   }
   else
   {
    ans=v[x-1];
   }

   
   // cout<<ans<<en;
   ll cn=0;
   for(int i=0;i<n;i++)
   {
    if(v[i]<=ans)
    {
        cn++;
    }
   }
   // cout<<cn<<" "<<ans<<en;

   if(cn!=x || ans<1)
   {
    cout<<-1<<en;
    return;
   }
   cout<<ans<<en;
   return;
      
     

  return 0;

}
 
