/*
  So basically here we have to check that this array is sorted or not 
  we are having a simple formula (max_in +  i + 1) % n which will push elements in vector sequentially
  
    So basically we have 3 cases :
      1-> if it is already sorted then we'll be returning 0
      2-> If it can be sorted then we'll go to maximum index and push elements from there and at last we'll check if it's sorted or not
      3-> else -1 will be printed means we can't sort the array by shifting elements
*/



#include <bits/stdc++.h>

#define ll          long long



int main(void)
{


        ll n;
        cin>>n;
        vector<int> v(n);
        int maxi=0, max_in=0;
        for(int i=0;i<n;i++)
        {
          cin>>v[i];
          if(v[i]>maxi)
          {
            maxi=v[i];
            max_in=i;
          }
        }
  
        if(is_sorted(v.begin(),v.end()))     // STL which checks that a given vector is sorted or not if sorted returns true else false
        {
            cout<<0<<en;              // if it is already sorted then we'll be returning 0
            return 0;
        }
  
        // this loop is for checking the last maximum number since we can have any number of maximum common element in our vector
  
        while(v[max_in]==maxi && max_in<n)
        {
            max_in++;
        }
  
        max_in--;
  
        ll ans = (n-1)-max_in;

        vector<int> temp; // temporary vector created 
          
  
        // pushing elements circulary from a single index to its ((max_in +  i + 1) % n)th Index

        for(int i=0;i<n;i++)
        {
            temp.pb(v[(max_in +  i + 1) % n]);
        }        
        
  
        if(is_sorted(temp.begin(),temp.end()))    // if its is sorted then we'll return steps need to shift elements in vector
        {
            cout<<ans<<en;
            return 0;
        }
  
  // at last if it is impossible to sort the array it will print -1 
        cout<<-1<<en;



  return 0;

}
 
